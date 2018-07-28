/* ASTI ELECTRONICS CORPORATION.
   v9-tesing in japan
   Date 08062018:
   WHC512
   PIN: 1-512
   ID CARD: 0->7
   ID CHIP : 0->3
   DATA MCP23S17: 0->7 (B0-B7),OR (A0-A7), Ox(A7-A0)(B7-B0)
   RECEIVE : *******
   RESPONCE: ****
*/
#include "SPI.h"
#include "MCP23S17.h"
#include "MCP23017.h"
#include "avr/wdt.h"
#include "define_variable.h"
#include "warehanessfunction.h"
void setup(){
  /**************************************/
  pinMode (LED, OUTPUT);
  pinMode (BUZZER, OUTPUT);
  pinMode (SEARCH_EN, OUTPUT);
  pinMode (TAPE, OUTPUT);
  /***************************************/
  digitalWrite(SEARCH_EN, HIGH);
  digitalWrite(TAPE, HIGH);
  digitalWrite(BUZZER, HIGH);
  init_interrupts_card();
  /************Setting SPI:***************/
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
  /*speed serial*************************/
  Serial.begin(250000);//MAX BAUDRATE
  Serial.println("HARNESS CHECKER MACHINE");
  /*init function**********************************/
  blinkLED();
  dem.reserve(4000);
  SEARCH_DISABLE();
  /***************KHOI TAO IC MCP23S17******************/
  init_chip();
  /***************KHOI TAO IC MCP23S17******************/
  init_chip_sub();
  /**************KIEM TRA KET NOI IC MCP MCP23S17*******/
  /**************TURN ON BUZZER*************************/
  BUZZER_OUT1();
  /**************SETTING WATCHDOG TIMER****************/
  wdt_enable(WDTO_4S);
}
/******************************************************/
void loop() {
  wdt_reset();//RESET WATCHDOG
  if ( stringComplete ){    
    //--------main CMD processing-----
    if (bcc_check(inputChar)){ 
    //if (true){
       /*SET PORT*/
      if (inputChar[0] == 'S'){
        //OO : SHOT
        //XX : OPEN
        port_1 = (inputChar[1]<<8)|(inputChar[2]);
        port_2 = (inputChar[3]<<8)|(inputChar[4]);
        
        setport(port_1); //setport len HIGH, OUTPUT MODES
        readport_1=readport(port_2);
        clearport(port_1);
        
        setport(port_2); //setport len HIGH, OUTPUT MODES
        readport_2=readport(port_1);
        clearport(port_2);
        
        if(readport_2==readport_1==1) Serial.write("OO");
        else Serial.write("XX");
        }
      /*SEARCH PIN*/
       else if (inputChar[0] == 'F'){
        SEARCH_ENABLE();    // Set pin search high level
        scandata_3();//scan tat ca PORT,luu vao data[]
        check();
        Serial.println("SEARCH:" + dem);
        SEARCH_DISABLE();}
       else if (inputChar[0] == 'H'){
          //setport(9);
          //time_=micros();
          //clear all chip
          Serial.print(":S:");
          for(int i=1;i<=512;i++){
            setport(i);
            scandata_3();
            check2();
            if(dem != "") Serial.print(String(i)+":"+dem+":");
            clearport2(i);
            }
          Serial.print("P:");
          //Serial.println(micros()-time_);
       }
      /*check single port*/
      else if (inputChar[0] == 'G'){
        port_1 = (inputChar[1]<<8)|(inputChar[2]);
        setport(port_1);
        scandata();//scan all data
        check_single_port();
        clearport(port_1);
        if(data_single_port[0]==port_1){
                                          if(data_single_port[1]==0) Serial.write(outputCharOk,4);//ok
                                          else {//print port shot
                                                outputChar[0]='X';
                                                outputChar[1]=data_single_port[1]>>8;
                                                outputChar[2]=data_single_port[1];
                                                outputChar[3]=outputChar[0]+outputChar[1]+outputChar[2];
                                                Serial.write(outputChar,4);
                                               }
                                         }
                                         else {//print port shot
                                               outputChar[0]='X';
                                               outputChar[1]=data_single_port[0]>>8;
                                               outputChar[2]=data_single_port[0];
                                               outputChar[3]=outputChar[0]+outputChar[1]+outputChar[2];
                                               Serial.write(outputChar,4);
                                               }
      }        
      /*TAPEOUT*/
      else if (inputChar[0] == 'T'){
        Serial.write("OO");
        TAPE_OUTPUT();
      }
      /*BUZZER1*/
      else if (inputChar[0] == 'B'){
        //Serial.println("Buzzer Out");
        Serial.write("OO");
        BUZZER_OUT1();
      }
      /*BUZZER3*/
      else if (inputChar[0] == 'U'){
        Serial.write("OO");
        BUZZER_OUT3();
      }
    }
    stringComplete = false;
    }
}
//-----------------------------------------------------------------------
void serialEvent(){
  int i=0;
  unsigned char inChar;
  while (Serial.available()) {
    // get the new byte:
    inChar = (unsigned char)Serial.read();
    // add it to the inputString:
    inputChar[i]=inChar;
    i++;
    //inputString += inChar;
    delayMicroseconds(50); // receiver time add 250000 bit/s = 32 us / 1 byte
    // if the incoming character is a newline, set a flag
    // Break if it received 6 byte
    if (i == 6) {
      stringComplete = true;break;
    }
  }
}

