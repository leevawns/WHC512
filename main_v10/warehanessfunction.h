#ifndef _warehanessfunction_h
#define _warehanessfunction_h

#include "MCP23S17.h"
#include "MCP23017.h"
#include "define_variable.h"
#include <arduino.h>
/*ALL FUNCTION
 * 
 * void init_chip(void): init begin() function for chip mcp
 * void Set_Input_All(void):Set input model for chip mcp
 * void blinkLED(void): bink led
 * void TAPE_OUTPUT(void): Tape out
 * void  SEARCH_ENABLE(void): enable search pin
 * void  SEARCH_DISABLE(void): disable search pin
 *  void BUZZER_OUT1(void): out buzzer 1
 *  void BUZZER_OUT3(void): out buzzer 2
 *  void scandata(void): scan data
 *  void test_ic(void): test ic
 *  void setport(int port): set port to output mode and high level
 *  void clearport(int port): set port to low and input mode
 *  void clear_data(): delete data[]
 *  String check(): return string: ex: 1=2= or e=
 *  String bcc_calculate(String str): return str+bcc
 *  bool bcc_test(String str): test bcc in str,return true if bcc ok and false if bcc fail, str format: string<bcc><\n>, this is bcc 1 byte, ex: "S1X\n", x is 1 byte bcc.
 */
/*RESET ALL I/O TO INPUT MODEL*/
void Set_Input_All(void){
  chip1.pinMode(INPUT);chip2.pinMode(INPUT);chip3.pinMode(INPUT);chip4.pinMode(INPUT);
  chip5.pinMode(INPUT);chip6.pinMode(INPUT);chip7.pinMode(INPUT);chip8.pinMode(INPUT);
  chip9.pinMode(INPUT);chip10.pinMode(INPUT);chip11.pinMode(INPUT);chip12.pinMode(INPUT);
  chip13.pinMode(INPUT);chip14.pinMode(INPUT);chip15.pinMode(INPUT);chip16.pinMode(INPUT);
  chip17.pinMode(INPUT);chip18.pinMode(INPUT);chip19.pinMode(INPUT);chip20.pinMode(INPUT);
  chip21.pinMode(INPUT);chip22.pinMode(INPUT);chip23.pinMode(INPUT);chip24.pinMode(INPUT);
  chip25.pinMode(INPUT);chip26.pinMode(INPUT);chip27.pinMode(INPUT);chip28.pinMode(INPUT);
  chip29.pinMode(INPUT);chip30.pinMode(INPUT);chip31.pinMode(INPUT);chip32.pinMode(INPUT);
}  
/*init all mcp23s17 chip*/
void init_chip(void){
  chip1.begin();chip2.begin();chip3.begin();chip4.begin();
  chip5.begin();chip6.begin();chip7.begin();chip8.begin();
  chip9.begin();chip10.begin();chip11.begin();chip12.begin();
  chip13.begin();chip14.begin();chip15.begin();chip16.begin();
  chip17.begin();chip18.begin();chip19.begin();chip20.begin();
  chip21.begin();chip22.begin();chip23.begin();chip24.begin();
  chip25.begin();chip26.begin();chip27.begin();chip28.begin();
  chip29.begin();chip30.begin();chip31.begin();chip32.begin();
  //set all chip mcp23s17
  Set_Input_All();    //Mr.Chung 3/11/2017
}
/**/
void init_chip_sub(void){
  chip_sub_1.begin();
  chip_sub_2.begin();
  chip_sub_3.begin();
  chip_sub_4.begin();
  }
/**/
void blinkLED(void){
  for (uint8_t i = 0; i<5; i++)
  {
    digitalWrite (LED, HIGH);   delay(100);
    digitalWrite (LED, LOW);    delay(100);
  }
}
/*control Tape*/
void TAPE_OUTPUT(void){
  digitalWrite (TAPE, LOW);
  delay(150);
  digitalWrite (TAPE, HIGH);  
}
/*SEARCH FUNCTION*/
void  SEARCH_ENABLE(void){
  //digitalWrite (SEARCH_EN, LOW);
  digitalWrite (SEARCH_EN, HIGH);
}
/**/
void  SEARCH_DISABLE(void){
  //digitalWrite (SEARCH_EN, HIGH);
  digitalWrite (SEARCH_EN, LOW);
}
/*CHUONG TRINH BUZZER*/
void BUZZER_OUT1(void){
      //tone(BUZZER, frequency, duration);
      digitalWrite (BUZZER, LOW); 
      delay(500);
      digitalWrite (BUZZER,HIGH);
 }
/**/
void BUZZER_OUT3(void){
      digitalWrite (BUZZER, LOW);    delay(500);
      digitalWrite (BUZZER,HIGH);    delay(100);
      digitalWrite (BUZZER, LOW);    delay(500);
      digitalWrite (BUZZER,HIGH);    delay(100);
      digitalWrite (BUZZER, LOW);    delay(500);
      digitalWrite (BUZZER,HIGH);    delay(100);
      //wdt_reset();
      /*
      tone(BUZZER, frequency, duration);delay(150);
      tone(BUZZER, frequency, duration);delay(150);
      tone(BUZZER, frequency, duration);delay(150);
      digitalWrite (BUZZER,HIGH);
      */
 }
/*scan all port save data[31] not use this because wrong command*/
void scandata(void){
for(char i=0;i<32;i++) data[i]=0xffff;//run
uint8_t read_sub_chip=0;
if(!digitalRead(CARD_1)){
   read_sub_chip=chip_sub_1.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0x03)!=0x03)   if(chip1.byteRead(IOCON)==0b00001000) data[0]=chip1.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C)   if(chip2.byteRead(IOCON)==0b00001000) data[1]=chip2.digitalRead();
   if((read_sub_chip&0x30)!=0x30)   if(chip3.byteRead(IOCON)==0b00001000) data[2]=chip3.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0)   if(chip4.byteRead(IOCON)==0b00001000) data[3]=chip4.digitalRead();
   }
if(!digitalRead(CARD_2)){  
   read_sub_chip=chip_sub_1.byteRead(MCP23017_GPIOA); 
   if((read_sub_chip&0x03)!=0x03) if(chip5.byteRead(IOCON)==0b00001000) data[4]=chip5.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip6.byteRead(IOCON)==0b00001000) data[5]=chip6.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip7.byteRead(IOCON)==0b00001000) data[6]=chip7.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip8.byteRead(IOCON)==0b00001000) data[7]=chip8.digitalRead();
   }
if(!digitalRead(CARD_3)){ 
   read_sub_chip=chip_sub_2.byteRead(MCP23017_GPIOB); 
   if((read_sub_chip&0x03)!=0x03)if(chip9.byteRead(IOCON)==0b00001000) data[8]=chip9.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C)if(chip10.byteRead(IOCON)==0b00001000) data[9]=chip10.digitalRead();
   if((read_sub_chip&0x30)!=0x30)if(chip11.byteRead(IOCON)==0b00001000) data[10]=chip11.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0)if(chip12.byteRead(IOCON)==0b00001000) data[11]=chip12.digitalRead();
   }
if(!digitalRead(CARD_4)){  
   read_sub_chip=chip_sub_2.byteRead(MCP23017_GPIOA);  
   if((read_sub_chip&0x03)!=0x03) if(chip13.byteRead(IOCON)==0b00001000) data[12]=chip13.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip14.byteRead(IOCON)==0b00001000) data[13]=chip14.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip15.byteRead(IOCON)==0b00001000) data[14]=chip15.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip16.byteRead(IOCON)==0b00001000) data[15]=chip16.digitalRead();
   }
if(!digitalRead(CARD_5)){
   read_sub_chip=chip_sub_3.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0x03)!=0x03) if(chip17.byteRead(IOCON)==0b00001000) data[16]=chip17.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip18.byteRead(IOCON)==0b00001000) data[17]=chip18.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip19.byteRead(IOCON)==0b00001000) data[18]=chip19.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip20.byteRead(IOCON)==0b00001000) data[19]=chip20.digitalRead();
   }
if(!digitalRead(CARD_6)){
   read_sub_chip=chip_sub_3.byteRead(MCP23017_GPIOA);
   if((read_sub_chip&0x03)!=0x03) if(chip21.byteRead(IOCON)==0b00001000) data[20]=chip21.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip22.byteRead(IOCON)==0b00001000) data[21]=chip22.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip23.byteRead(IOCON)==0b00001000) data[22]=chip23.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip24.byteRead(IOCON)==0b00001000) data[23]=chip24.digitalRead();
   }
if(!digitalRead(CARD_7)){
   read_sub_chip=chip_sub_4.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0x03)!=0x03) if(chip25.byteRead(IOCON)==0b00001000) data[24]=chip25.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip26.byteRead(IOCON)==0b00001000) data[25]=chip26.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip27.byteRead(IOCON)==0b00001000) data[26]=chip27.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip28.byteRead(IOCON)==0b00001000) data[27]=chip28.digitalRead();
   }
if(!digitalRead(CARD_8)){
   read_sub_chip=chip_sub_4.byteRead(MCP23017_GPIOA);
   if((read_sub_chip&0x03)!=0x03) if(chip29.byteRead(IOCON)==0b00001000) data[28]=chip29.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip30.byteRead(IOCON)==0b00001000) data[29]=chip30.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip31.byteRead(IOCON)==0b00001000) data[30]=chip31.digitalRead();
   if((read_sub_chip&0xC0)!=0xC0) if(chip32.byteRead(IOCON)==0b00001000) data[31]=chip32.digitalRead();
   }}
/**/
/*scan all port save data[31] use interrupt*/
void scandata_2(void){
for(char i=0;i<32;i++) data[i]=0xffff;//run
uint8_t read_sub_chip=0;
if(!digitalRead(CARD_1)){
   read_sub_chip=chip_sub_1.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0xC0)!=0xC0)   if(chip1.byteRead(IOCON)==0b00001000) data[0]=chip1.digitalRead();
   if((read_sub_chip&0x30)!=0x30)   if(chip2.byteRead(IOCON)==0b00001000) data[1]=chip2.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C)   if(chip3.byteRead(IOCON)==0b00001000) data[2]=chip3.digitalRead();
   if((read_sub_chip&0x03)!=0x03)   if(chip4.byteRead(IOCON)==0b00001000) data[3]=chip4.digitalRead();
   }
if(!digitalRead(CARD_2)){  
   read_sub_chip=chip_sub_1.byteRead(MCP23017_GPIOA); 
   if((read_sub_chip&0xC0)!=0xC0) if(chip5.byteRead(IOCON)==0b00001000) data[4]=chip5.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip6.byteRead(IOCON)==0b00001000) data[5]=chip6.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip7.byteRead(IOCON)==0b00001000) data[6]=chip7.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip8.byteRead(IOCON)==0b00001000) data[7]=chip8.digitalRead();
   }
if(!digitalRead(CARD_3)){ 
   read_sub_chip=chip_sub_2.byteRead(MCP23017_GPIOB); 
   if((read_sub_chip&0xC0)!=0xC0)if(chip9.byteRead(IOCON)==0b00001000) data[8]=chip9.digitalRead();
   if((read_sub_chip&0x30)!=0x30)if(chip10.byteRead(IOCON)==0b00001000) data[9]=chip10.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C)if(chip11.byteRead(IOCON)==0b00001000) data[10]=chip11.digitalRead();
   if((read_sub_chip&0x03)!=0x03)if(chip12.byteRead(IOCON)==0b00001000) data[11]=chip12.digitalRead();
   }
if(!digitalRead(CARD_4)){  
   read_sub_chip=chip_sub_2.byteRead(MCP23017_GPIOA);  
   if((read_sub_chip&0xC0)!=0xC0) if(chip13.byteRead(IOCON)==0b00001000) data[12]=chip13.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip14.byteRead(IOCON)==0b00001000) data[13]=chip14.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip15.byteRead(IOCON)==0b00001000) data[14]=chip15.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip16.byteRead(IOCON)==0b00001000) data[15]=chip16.digitalRead();
   }
if(!digitalRead(CARD_5)){
   read_sub_chip=chip_sub_3.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0xC0)!=0xC0) if(chip17.byteRead(IOCON)==0b00001000) data[16]=chip17.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip18.byteRead(IOCON)==0b00001000) data[17]=chip18.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip19.byteRead(IOCON)==0b00001000) data[18]=chip19.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip20.byteRead(IOCON)==0b00001000) data[19]=chip20.digitalRead();
   }
if(!digitalRead(CARD_6)){
   read_sub_chip=chip_sub_3.byteRead(MCP23017_GPIOA);
   if((read_sub_chip&0xC0)!=0xC0) if(chip21.byteRead(IOCON)==0b00001000) data[20]=chip21.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip22.byteRead(IOCON)==0b00001000) data[21]=chip22.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip23.byteRead(IOCON)==0b00001000) data[22]=chip23.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip24.byteRead(IOCON)==0b00001000) data[23]=chip24.digitalRead();
   }
if(!digitalRead(CARD_7)){
   read_sub_chip=chip_sub_4.byteRead(MCP23017_GPIOB);
   if((read_sub_chip&0xC0)!=0xC0) if(chip25.byteRead(IOCON)==0b00001000) data[24]=chip25.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip26.byteRead(IOCON)==0b00001000) data[25]=chip26.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip27.byteRead(IOCON)==0b00001000) data[26]=chip27.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip28.byteRead(IOCON)==0b00001000) data[27]=chip28.digitalRead();
   }
if(!digitalRead(CARD_8)){
   read_sub_chip=chip_sub_4.byteRead(MCP23017_GPIOA);
   if((read_sub_chip&0xC0)!=0xC0) if(chip29.byteRead(IOCON)==0b00001000) data[28]=chip29.digitalRead();
   if((read_sub_chip&0x30)!=0x30) if(chip30.byteRead(IOCON)==0b00001000) data[29]=chip30.digitalRead();
   if((read_sub_chip&0x0C)!=0x0C) if(chip31.byteRead(IOCON)==0b00001000) data[30]=chip31.digitalRead();
   if((read_sub_chip&0x03)!=0x03) if(chip32.byteRead(IOCON)==0b00001000) data[31]=chip32.digitalRead();
   }}
/*scan all port save data[31] not use interrupt*/
/*scan all port save data[31] use interrupt*/
void scandata_3(void){
for(char i=0;i<32;i++) data[i]=0xffff;//run
uint16_t read_sub_chip=0XFF;

if((!digitalRead(CARD_2))|(!digitalRead(CARD_1))){  
   read_sub_chip=chip_sub_1.wordRead(MCP23017_GPIOA); 
   if(chip5.byteRead(IOCON)==0b00001000) data[4]=chip5.digitalRead();
   if(chip6.byteRead(IOCON)==0b00001000) data[5]=chip6.digitalRead();
   if(chip7.byteRead(IOCON)==0b00001000) data[6]=chip7.digitalRead();
   if(chip8.byteRead(IOCON)==0b00001000) data[7]=chip8.digitalRead();
   if(chip1.byteRead(IOCON)==0b00001000) data[0]=chip1.digitalRead();
   if(chip2.byteRead(IOCON)==0b00001000) data[1]=chip2.digitalRead();
   if(chip3.byteRead(IOCON)==0b00001000) data[2]=chip3.digitalRead();
   if(chip4.byteRead(IOCON)==0b00001000) data[3]=chip4.digitalRead();
   }
if((!digitalRead(CARD_4))|(!digitalRead(CARD_3))){  
   read_sub_chip=chip_sub_2.wordRead(MCP23017_GPIOA);  
   if(chip13.byteRead(IOCON)==0b00001000) data[12]=chip13.digitalRead();
   if(chip14.byteRead(IOCON)==0b00001000) data[13]=chip14.digitalRead();
   if(chip15.byteRead(IOCON)==0b00001000) data[14]=chip15.digitalRead();
   if(chip16.byteRead(IOCON)==0b00001000) data[15]=chip16.digitalRead(); 
   if(chip9.byteRead(IOCON)==0b00001000) data[8]=chip9.digitalRead();
   if(chip10.byteRead(IOCON)==0b00001000) data[9]=chip10.digitalRead();
   if(chip11.byteRead(IOCON)==0b00001000) data[10]=chip11.digitalRead();
   if(chip12.byteRead(IOCON)==0b00001000) data[11]=chip12.digitalRead();
   }
if((!digitalRead(CARD_6))|(!digitalRead(CARD_5))){
   read_sub_chip=chip_sub_3.wordRead(MCP23017_GPIOA);
   if(chip21.byteRead(IOCON)==0b00001000) data[20]=chip21.digitalRead();
   if(chip22.byteRead(IOCON)==0b00001000) data[21]=chip22.digitalRead();
   if(chip23.byteRead(IOCON)==0b00001000) data[22]=chip23.digitalRead();
   if(chip24.byteRead(IOCON)==0b00001000) data[23]=chip24.digitalRead();
   if(chip17.byteRead(IOCON)==0b00001000) data[16]=chip17.digitalRead();
   if(chip18.byteRead(IOCON)==0b00001000) data[17]=chip18.digitalRead();
   if(chip19.byteRead(IOCON)==0b00001000) data[18]=chip19.digitalRead();
   if(chip20.byteRead(IOCON)==0b00001000) data[19]=chip20.digitalRead();
   }
if((!digitalRead(CARD_8))|(!digitalRead(CARD_7))){
   read_sub_chip=chip_sub_4.wordRead(MCP23017_GPIOA);
   if(chip29.byteRead(IOCON)==0b00001000) data[28]=chip29.digitalRead();
   if(chip30.byteRead(IOCON)==0b00001000) data[29]=chip30.digitalRead();
   if(chip31.byteRead(IOCON)==0b00001000) data[30]=chip31.digitalRead();
   if(chip32.byteRead(IOCON)==0b00001000) data[31]=chip32.digitalRead();
   if(chip25.byteRead(IOCON)==0b00001000) data[24]=chip25.digitalRead();
   if(chip26.byteRead(IOCON)==0b00001000) data[25]=chip26.digitalRead();
   if(chip27.byteRead(IOCON)==0b00001000) data[26]=chip27.digitalRead();
   if(chip28.byteRead(IOCON)==0b00001000) data[27]=chip28.digitalRead();
   }
}
/*scan all port save data[31] not use interrupt*/
void scandata_1(void){
for(char i=0;i<32;i++) data[i]=0XFFFF;//run
if(chip1.byteRead(IOCON)==0b00001000) data[0]=chip1.digitalRead();
if(chip2.byteRead(IOCON)==0b00001000) data[1]=chip2.digitalRead();
if(chip3.byteRead(IOCON)==0b00001000) data[2]=chip3.digitalRead();
if(chip4.byteRead(IOCON)==0b00001000) data[3]=chip4.digitalRead();
if(chip5.byteRead(IOCON)==0b00001000) data[4]=chip5.digitalRead();
if(chip6.byteRead(IOCON)==0b00001000) data[5]=chip6.digitalRead();
if(chip7.byteRead(IOCON)==0b00001000) data[6]=chip7.digitalRead();
if(chip8.byteRead(IOCON)==0b00001000) data[7]=chip8.digitalRead();
if(chip9.byteRead(IOCON)==0b00001000) data[8]=chip9.digitalRead();
if(chip10.byteRead(IOCON)==0b00001000) data[9]=chip10.digitalRead();
if(chip11.byteRead(IOCON)==0b00001000) data[10]=chip11.digitalRead();
if(chip12.byteRead(IOCON)==0b00001000) data[11]=chip12.digitalRead();
if(chip13.byteRead(IOCON)==0b00001000) data[12]=chip13.digitalRead();
if(chip14.byteRead(IOCON)==0b00001000) data[13]=chip14.digitalRead();
if(chip15.byteRead(IOCON)==0b00001000) data[14]=chip15.digitalRead();
if(chip16.byteRead(IOCON)==0b00001000) data[15]=chip16.digitalRead();
if(chip17.byteRead(IOCON)==0b00001000) data[16]=chip17.digitalRead();
if(chip18.byteRead(IOCON)==0b00001000) data[17]=chip18.digitalRead();
if(chip19.byteRead(IOCON)==0b00001000) data[18]=chip19.digitalRead();
if(chip20.byteRead(IOCON)==0b00001000) data[19]=chip20.digitalRead();
if(chip21.byteRead(IOCON)==0b00001000) data[20]=chip21.digitalRead();
if(chip22.byteRead(IOCON)==0b00001000) data[21]=chip22.digitalRead();
if(chip23.byteRead(IOCON)==0b00001000) data[22]=chip23.digitalRead();
if(chip24.byteRead(IOCON)==0b00001000) data[23]=chip24.digitalRead();
if(chip25.byteRead(IOCON)==0b00001000) data[24]=chip25.digitalRead();
if(chip26.byteRead(IOCON)==0b00001000) data[25]=chip26.digitalRead();
if(chip27.byteRead(IOCON)==0b00001000) data[26]=chip27.digitalRead();
if(chip28.byteRead(IOCON)==0b00001000) data[27]=chip28.digitalRead();
if(chip29.byteRead(IOCON)==0b00001000) data[28]=chip29.digitalRead();
if(chip30.byteRead(IOCON)==0b00001000) data[29]=chip30.digitalRead();
if(chip31.byteRead(IOCON)==0b00001000) data[30]=chip31.digitalRead();
if(chip32.byteRead(IOCON)==0b00001000) data[31]=chip32.digitalRead();}
/**/
void setport(unsigned int port){
  id_card = (port-1)/64;
  id_ic = ((port-1)%64)/16;
  id_pin = (((port-1)%64)%16)+1;
  switch (id_card){
    case 0: 
      switch(id_ic){
        case 0: chip1.pinMode(id_pin,OUTPUT); chip1.digitalWrite(id_pin,LOW);
                 break;
        case 1: chip2.pinMode(id_pin,OUTPUT); chip2.digitalWrite(id_pin,LOW);
                 break;
        case 2: chip3.pinMode(id_pin,OUTPUT); chip3.digitalWrite(id_pin,LOW);
                 break;
        case 3: chip4.pinMode(id_pin,OUTPUT); chip4.digitalWrite(id_pin,LOW);
                break;

      default:
         break;
        }
     break;   
    case 1:
      switch(id_ic){
      case 0: chip5.pinMode(id_pin,OUTPUT); chip5.digitalWrite(id_pin,LOW);
               break;
      case 1: chip6.pinMode(id_pin,OUTPUT); chip6.digitalWrite(id_pin,LOW);
               break;
      case 2: chip7.pinMode(id_pin,OUTPUT); chip7.digitalWrite(id_pin,LOW);
               break;
      case 3: chip8.pinMode(id_pin,OUTPUT); chip8.digitalWrite(id_pin,LOW);
         break;
      default:
         break;    
    }
    break;
    case 2:
      switch(id_ic){
      case 0: chip9.pinMode(id_pin,OUTPUT); chip9.digitalWrite(id_pin,LOW);
               break;
      case 1: chip10.pinMode(id_pin,OUTPUT); chip10.digitalWrite(id_pin,LOW);
               break;
      case 2: chip11.pinMode(id_pin,OUTPUT); chip11.digitalWrite(id_pin,LOW);
               break;
      case 3: chip12.pinMode(id_pin,OUTPUT); chip12.digitalWrite(id_pin,LOW);
         break;
        default:
         break;    
    }
    break;
    case 3:
      switch(id_ic){
      case 0: chip13.pinMode(id_pin,OUTPUT); chip13.digitalWrite(id_pin,LOW);
               break;
      case 1: chip14.pinMode(id_pin,OUTPUT); chip14.digitalWrite(id_pin,LOW);
               break;
      case 2: chip15.pinMode(id_pin,OUTPUT); chip15.digitalWrite(id_pin,LOW);
               break;
      case 3: chip16.pinMode(id_pin,OUTPUT); chip16.digitalWrite(id_pin,LOW);
         break;   
    
    
        default:
         break;    
    } 
    break;
    case 4:
      switch(id_ic){
      case 0: chip17.pinMode(id_pin,OUTPUT); chip17.digitalWrite(id_pin,LOW);
               break;
      case 1: chip18.pinMode(id_pin,OUTPUT); chip18.digitalWrite(id_pin,LOW);
               break;
      case 2: chip19.pinMode(id_pin,OUTPUT); chip19.digitalWrite(id_pin,LOW);
               break;
      case 3: chip20.pinMode(id_pin,OUTPUT); chip20.digitalWrite(id_pin,LOW);
         break;  
    
    
        default:
         break;    
    } 
    break;
    case 5:
      switch(id_ic){
      case 0: chip21.pinMode(id_pin,OUTPUT); chip21.digitalWrite(id_pin,LOW);
               break;
      case 1: chip22.pinMode(id_pin,OUTPUT); chip22.digitalWrite(id_pin,LOW);
               break;
      case 2: chip23.pinMode(id_pin,OUTPUT); chip23.digitalWrite(id_pin,LOW);
               break;
      case 3: chip24.pinMode(id_pin,OUTPUT); chip24.digitalWrite(id_pin,LOW);
         break;   
    
    
        default:
         break;    
    }
    break;
    case 6:
      switch(id_ic){
      case 0: chip25.pinMode(id_pin,OUTPUT); chip25.digitalWrite(id_pin,LOW);
               break;
      case 1: chip26.pinMode(id_pin,OUTPUT); chip26.digitalWrite(id_pin,LOW);
               break;
      case 2: chip27.pinMode(id_pin,OUTPUT); chip27.digitalWrite(id_pin,LOW);
               break;
      case 3: chip28.pinMode(id_pin,OUTPUT); chip28.digitalWrite(id_pin,LOW);
         break;
    
    
    
        default:
         break;    
    }
    break;
    case 7:
      switch(id_ic){
      case 0: chip29.pinMode(id_pin,OUTPUT); chip29.digitalWrite(id_pin,LOW);
               break;
      case 1: chip30.pinMode(id_pin,OUTPUT); chip30.digitalWrite(id_pin,LOW);
               break;
      case 2: chip31.pinMode(id_pin,OUTPUT); chip31.digitalWrite(id_pin,LOW);
               break;
      case 3: chip32.pinMode(id_pin,OUTPUT); chip32.digitalWrite(id_pin,LOW);
         break;    
    
        default:
         break;    
    }
    break;
    /*
    case 8:
      switch(id_ic){
      case 0: chip33.pinMode(id_pin,OUTPUT); chip33.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip34.pinMode(id_pin,OUTPUT); chip34.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip35.pinMode(id_pin,OUTPUT); chip35.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip36.pinMode(id_pin,OUTPUT); chip36.digitalWrite(id_pin,HIGH);
         break;

    
        default:
         break;    
    }
    break;
    case 9:
      switch(id_ic){
      case 0: chip37.pinMode(id_pin,OUTPUT); chip37.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip38.pinMode(id_pin,OUTPUT); chip38.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip39.pinMode(id_pin,OUTPUT); chip39.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip40.pinMode(id_pin,OUTPUT); chip40.digitalWrite(id_pin,HIGH);
         break;

        default:
         break;    
    }
    break;
    case 10:
      switch(id_ic){
      case 0: chip41.pinMode(id_pin,OUTPUT); chip41.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip42.pinMode(id_pin,OUTPUT); chip42.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip43.pinMode(id_pin,OUTPUT); chip43.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip44.pinMode(id_pin,OUTPUT); chip44.digitalWrite(id_pin,HIGH);
         break;
 
    
        default:
         break;    
    }
    break;
    case 11:
      switch(id_ic){
      case 0: chip45.pinMode(id_pin,OUTPUT); chip45.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip46.pinMode(id_pin,OUTPUT); chip46.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip47.pinMode(id_pin,OUTPUT); chip47.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip48.pinMode(id_pin,OUTPUT); chip48.digitalWrite(id_pin,HIGH);
         break;
    
    
        default:
         break;    
    }
    break;
    case 12:
      switch(id_ic){
      case 0: chip49.pinMode(id_pin,OUTPUT); chip49.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip50.pinMode(id_pin,OUTPUT); chip50.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip51.pinMode(id_pin,OUTPUT); chip51.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip52.pinMode(id_pin,OUTPUT); chip52.digitalWrite(id_pin,HIGH);
         break;
   
    
        default:
         break;    
    } 
    break;
    case 13:
      switch(id_ic){
      case 0: chip53.pinMode(id_pin,OUTPUT); chip53.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip54.pinMode(id_pin,OUTPUT); chip54.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip55.pinMode(id_pin,OUTPUT); chip55.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip56.pinMode(id_pin,OUTPUT); chip56.digitalWrite(id_pin,HIGH);
         break;
    
    
        default:
         break;    
    }
    break;
    case 14:
      switch(id_ic){
      case 0: chip57.pinMode(id_pin,OUTPUT); chip57.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip58.pinMode(id_pin,OUTPUT); chip58.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip59.pinMode(id_pin,OUTPUT); chip59.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip60.pinMode(id_pin,OUTPUT); chip60.digitalWrite(id_pin,HIGH);
         break;

    
        default:
         break;    
    }
    break;
    case 15:
      switch(id_ic){
      case 0: chip61.pinMode(id_pin,OUTPUT); chip61.digitalWrite(id_pin,HIGH);
               break;
      case 1: chip62.pinMode(id_pin,OUTPUT); chip62.digitalWrite(id_pin,HIGH);
               break;
      case 2: chip63.pinMode(id_pin,OUTPUT); chip63.digitalWrite(id_pin,HIGH);
               break;
      case 3: chip64.pinMode(id_pin,OUTPUT); chip64.digitalWrite(id_pin,HIGH);
         break;
        default:
         break;    
    }*/
    default:
         break;
  }
}
/**/
void clearport(unsigned int port){
  id_card = (port-1)/64;
  id_ic = ((port-1)%64)/16;
  id_pin = (((port-1)%64)%16)+1;
  switch (id_card){
    case 0: 
      switch(id_ic){
      case 0: chip1.digitalWrite(0);chip1.pinMode(0); 
               break;
      case 1:  chip2.digitalWrite(0);chip2.pinMode(0);
               break;
      case 2:  chip3.digitalWrite(0);chip3.pinMode(0);
               break;
      case 3:  chip4.digitalWrite(0);chip4.pinMode(0);
         break;

      default:
         break;
        }break;
    case 1:
      switch(id_ic){
      case 0:  chip5.digitalWrite(0);chip5.pinMode(0);
               break;
      case 1: chip6.digitalWrite(0);chip6.pinMode(0); 
               break;
      case 2: chip7.digitalWrite(0);chip7.pinMode(0); 
               break;
      case 3: chip8.digitalWrite(0);chip8.pinMode(0); 
         break;
      default:
         break;    
    }break;
    case 2:
      switch(id_ic){
      case 0:  chip9.digitalWrite(0);chip9.pinMode(0);
               break;
      case 1: chip10.digitalWrite(0);chip10.pinMode(0); 
               break;
      case 2: chip11.digitalWrite(0);chip11.pinMode(0); 
               break;
      case 3: chip12.digitalWrite(0);chip12.pinMode(0); 
               break;
      default:
         break;    
    }break;
    case 3:
      switch(id_ic){
      case 0:  chip13.digitalWrite(0);chip13.pinMode(0);
               break;
      case 1: chip14.digitalWrite(0);chip14.pinMode(0); 
               break;
      case 2: chip15.digitalWrite(0);chip15.pinMode(0); 
               break;
      case 3: chip16.digitalWrite(0);chip16.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 4:
      switch(id_ic){
      case 0:  chip17.digitalWrite(0);chip17.pinMode(0);
               break;
      case 1: chip18.digitalWrite(0);chip18.pinMode(0); 
               break;
      case 2: chip19.digitalWrite(0);chip19.pinMode(0); 
               break;
      case 3: chip20.digitalWrite(0);chip20.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 5:
      switch(id_ic){
      case 0:  chip21.digitalWrite(0);chip21.pinMode(0);
               break;
      case 1: chip22.digitalWrite(0);chip22.pinMode(0); 
               break;
      case 2: chip23.digitalWrite(0);chip23.pinMode(0); 
               break;
      case 3: chip24.digitalWrite(0);chip24.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 6:
      switch(id_ic){
      case 0:  chip25.digitalWrite(0);chip25.pinMode(0);
               break;
      case 1: chip26.digitalWrite(0);chip26.pinMode(0); 
               break;
      case 2: chip27.digitalWrite(0);chip27.pinMode(0); 
               break;
      case 3: chip28.digitalWrite(0);chip28.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 7:
      switch(id_ic){
      case 0:  chip29.digitalWrite(0);chip29.pinMode(0);
               break;
      case 1: chip30.digitalWrite(0);chip30.pinMode(0); 
               break;
      case 2: chip31.digitalWrite(0);chip31.pinMode(0); 
               break;
      case 3: chip32.digitalWrite(0);chip32.pinMode(0); 
               break;
        default:
         break;    
    }break;
    /*
    case 8:
      switch(id_ic){
      case 0:  chip33.digitalWrite(0);chip33.pinMode(0);
               break;
      case 1: chip34.digitalWrite(0);chip34.pinMode(0); 
               break;
      case 2: chip35.digitalWrite(0);chip35.pinMode(0); 
               break;
      case 3: chip36.digitalWrite(0);chip36.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 9:
      switch(id_ic){
      case 0:  chip37.digitalWrite(0);chip37.pinMode(0);
               break;
      case 1: chip38.digitalWrite(0);chip38.pinMode(0); 
               break;
      case 2: chip39.digitalWrite(0);chip39.pinMode(0); 
               break;
      case 3: chip40.digitalWrite(0);chip40.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 10:
      switch(id_ic){
      case 0:  chip41.digitalWrite(0);chip41.pinMode(0);
               break;
      case 1: chip42.digitalWrite(0);chip42.pinMode(0); 
               break;
      case 2: chip43.digitalWrite(0);chip43.pinMode(0); 
               break;
      case 3: chip44.digitalWrite(0);chip44.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 11:
      switch(id_ic){
      case 0:  chip45.digitalWrite(0);chip45.pinMode(0);
               break;
      case 1: chip46.digitalWrite(0);chip46.pinMode(0); 
               break;
      case 2: chip47.digitalWrite(0);chip47.pinMode(0); 
               break;
      case 3: chip48.digitalWrite(0);chip48.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 12:
      switch(id_ic){
      case 0:  chip49.digitalWrite(0);chip49.pinMode(0);
               break;
      case 1: chip50.digitalWrite(0);chip50.pinMode(0); 
               break;
      case 2: chip51.digitalWrite(0);chip51.pinMode(0); 
               break;
      case 3: chip52.digitalWrite(0);chip52.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 13:
      switch(id_ic){
      case 0:  chip53.digitalWrite(0);chip53.pinMode(0);
               break;
      case 1: chip54.digitalWrite(0);chip54.pinMode(0); 
               break;
      case 2: chip55.digitalWrite(0);chip55.pinMode(0); 
               break;
      case 3: chip56.digitalWrite(0);chip56.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 14:
      switch(id_ic){
       case 0:  chip57.digitalWrite(0);chip57.pinMode(0);
               break;
      case 1: chip58.digitalWrite(0);chip58.pinMode(0); 
               break;
      case 2: chip59.digitalWrite(0);chip59.pinMode(0); 
               break;
      case 3: chip60.digitalWrite(0);chip60.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 15:
      switch(id_ic){
      case 0:  chip61.digitalWrite(0);chip61.pinMode(0);
               break;
      case 1: chip62.digitalWrite(0);chip62.pinMode(0); 
               break;
      case 2: chip63.digitalWrite(0);chip63.pinMode(0); 
               break;
      case 3: chip64.digitalWrite(0);chip64.pinMode(0); 
               break;
      default:
               break;   
    }   */
default:
         break;     
  }
}  
/**/
void clearport2(unsigned int port){
  id_card = (port-1)/64;
  id_ic = ((port-1)%64)/16;
  id_pin = (((port-1)%64)%16)+1;
  switch (id_card){
    case 0: 
      switch(id_ic){
      case 0: chip1.digitalWrite(id_pin,HIGH);chip1.pinMode(id_pin,INPUT);
               break;
      case 1:  chip2.digitalWrite(id_pin,HIGH);chip2.pinMode(id_pin,INPUT);
               break;
      case 2:  chip3.digitalWrite(id_pin,HIGH);chip3.pinMode(id_pin,INPUT);
               break;
      case 3:  chip4.digitalWrite(id_pin,HIGH);chip4.pinMode(id_pin,INPUT);
         break;

      default:
         break;
        }break;
    case 1:
      switch(id_ic){
      case 0:  chip5.digitalWrite(id_pin,HIGH);chip5.pinMode(id_pin,INPUT);
               break;
      case 1: chip6.digitalWrite(id_pin,HIGH);chip6.pinMode(id_pin,INPUT); 
               break;
      case 2: chip7.digitalWrite(id_pin,HIGH);chip7.pinMode(id_pin,INPUT); 
               break;
      case 3: chip8.digitalWrite(id_pin,HIGH);chip8.pinMode(id_pin,INPUT); 
         break;
      default:
         break;    
    }break;
    case 2:
      switch(id_ic){
      case 0:  chip9.digitalWrite(id_pin,HIGH);chip9.pinMode(id_pin,INPUT);
               break;
      case 1: chip10.digitalWrite(id_pin,HIGH);chip10.pinMode(id_pin,INPUT); 
               break;
      case 2: chip11.digitalWrite(id_pin,HIGH);chip11.pinMode(id_pin,INPUT); 
               break;
      case 3: chip12.digitalWrite(id_pin,HIGH);chip12.pinMode(id_pin,INPUT); 
               break;
      default:
         break;    
    }break;
    case 3:
      switch(id_ic){
      case 0:  chip13.digitalWrite(id_pin,HIGH);chip13.pinMode(id_pin,INPUT);
               break;
      case 1: chip14.digitalWrite(id_pin,HIGH);chip14.pinMode(id_pin,INPUT); 
               break;
      case 2: chip15.digitalWrite(id_pin,HIGH);chip15.pinMode(id_pin,INPUT); 
               break;
      case 3: chip16.digitalWrite(id_pin,HIGH);chip16.pinMode(id_pin,INPUT); 
               break;
        default:
         break;    
    } break;
    case 4:
      switch(id_ic){
      case 0:  chip17.digitalWrite(id_pin,HIGH);chip17.pinMode(id_pin,INPUT);
               break;
      case 1: chip18.digitalWrite(id_pin,HIGH);chip18.pinMode(id_pin,INPUT); 
               break;
      case 2: chip19.digitalWrite(id_pin,HIGH);chip19.pinMode(id_pin,INPUT); 
               break;
      case 3: chip20.digitalWrite(id_pin,HIGH);chip20.pinMode(id_pin,INPUT); 
               break;
        default:
         break;    
    } break;
    case 5:
      switch(id_ic){
      case 0:  chip21.digitalWrite(id_pin,HIGH);chip21.pinMode(id_pin,INPUT);
               break;
      case 1: chip22.digitalWrite(id_pin,HIGH);chip22.pinMode(id_pin,INPUT); 
               break;
      case 2: chip23.digitalWrite(id_pin,HIGH);chip23.pinMode(id_pin,INPUT); 
               break;
      case 3: chip24.digitalWrite(id_pin,HIGH);chip24.pinMode(id_pin,INPUT); 
               break;
        default:
         break;    
    }break;
    case 6:
      switch(id_ic){
      case 0:  chip25.digitalWrite(id_pin,HIGH);chip25.pinMode(id_pin,INPUT);
               break;
      case 1: chip26.digitalWrite(id_pin,HIGH);chip26.pinMode(id_pin,INPUT); 
               break;
      case 2: chip27.digitalWrite(id_pin,HIGH);chip27.pinMode(id_pin,INPUT); 
               break;
      case 3: chip28.digitalWrite(id_pin,HIGH);chip28.pinMode(id_pin,INPUT); 
               break;
        default:
         break;    
    }break;
    case 7:
      switch(id_ic){
      case 0:  chip29.digitalWrite(id_pin,HIGH);chip29.pinMode(id_pin,INPUT);
               break;
      case 1: chip30.digitalWrite(id_pin,HIGH);chip30.pinMode(id_pin,INPUT); 
               break;
      case 2: chip31.digitalWrite(id_pin,HIGH);chip31.pinMode(id_pin,INPUT); 
               break;
      case 3: chip32.digitalWrite(id_pin,HIGH);chip32.pinMode(id_pin,INPUT); 
               break;
        default:
         break;    
    }break;
    /*
    case 8:
      switch(id_ic){
      case 0:  chip33.digitalWrite(0);chip33.pinMode(0);
               break;
      case 1: chip34.digitalWrite(0);chip34.pinMode(0); 
               break;
      case 2: chip35.digitalWrite(0);chip35.pinMode(0); 
               break;
      case 3: chip36.digitalWrite(0);chip36.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 9:
      switch(id_ic){
      case 0:  chip37.digitalWrite(0);chip37.pinMode(0);
               break;
      case 1: chip38.digitalWrite(0);chip38.pinMode(0); 
               break;
      case 2: chip39.digitalWrite(0);chip39.pinMode(0); 
               break;
      case 3: chip40.digitalWrite(0);chip40.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 10:
      switch(id_ic){
      case 0:  chip41.digitalWrite(0);chip41.pinMode(0);
               break;
      case 1: chip42.digitalWrite(0);chip42.pinMode(0); 
               break;
      case 2: chip43.digitalWrite(0);chip43.pinMode(0); 
               break;
      case 3: chip44.digitalWrite(0);chip44.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 11:
      switch(id_ic){
      case 0:  chip45.digitalWrite(0);chip45.pinMode(0);
               break;
      case 1: chip46.digitalWrite(0);chip46.pinMode(0); 
               break;
      case 2: chip47.digitalWrite(0);chip47.pinMode(0); 
               break;
      case 3: chip48.digitalWrite(0);chip48.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 12:
      switch(id_ic){
      case 0:  chip49.digitalWrite(0);chip49.pinMode(0);
               break;
      case 1: chip50.digitalWrite(0);chip50.pinMode(0); 
               break;
      case 2: chip51.digitalWrite(0);chip51.pinMode(0); 
               break;
      case 3: chip52.digitalWrite(0);chip52.pinMode(0); 
               break;
        default:
         break;    
    } break;
    case 13:
      switch(id_ic){
      case 0:  chip53.digitalWrite(0);chip53.pinMode(0);
               break;
      case 1: chip54.digitalWrite(0);chip54.pinMode(0); 
               break;
      case 2: chip55.digitalWrite(0);chip55.pinMode(0); 
               break;
      case 3: chip56.digitalWrite(0);chip56.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 14:
      switch(id_ic){
       case 0:  chip57.digitalWrite(0);chip57.pinMode(0);
               break;
      case 1: chip58.digitalWrite(0);chip58.pinMode(0); 
               break;
      case 2: chip59.digitalWrite(0);chip59.pinMode(0); 
               break;
      case 3: chip60.digitalWrite(0);chip60.pinMode(0); 
               break;
        default:
         break;    
    }break;
    case 15:
      switch(id_ic){
      case 0:  chip61.digitalWrite(0);chip61.pinMode(0);
               break;
      case 1: chip62.digitalWrite(0);chip62.pinMode(0); 
               break;
      case 2: chip63.digitalWrite(0);chip63.pinMode(0); 
               break;
      case 3: chip64.digitalWrite(0);chip64.pinMode(0); 
               break;
      default:
               break;   
    }   */
default:
         break;     
  }
}  
/**/
bool readport(unsigned int port){
  id_card = (port-1)/64;
  id_ic = ((port-1)%64)/16;
  id_pin = (((port-1)%64)%16)+1;
  switch (id_card){
    case 0: 
      switch(id_ic){
        case 0: if(chip1.byteRead(IOCON)==0b00001000) return chip1.digitalRead(id_pin); else return 0;
                 break;
        case 1: if(chip2.byteRead(IOCON)==0b00001000) return chip2.digitalRead(id_pin); else return 0;
                 break;
        case 2: if(chip3.byteRead(IOCON)==0b00001000) return chip3.digitalRead(id_pin); else return 0;
                 break;
        case 3: if(chip4.byteRead(IOCON)==0b00001000) return chip4.digitalRead(id_pin); else return 0;
                break;

      default:
         break;
        }
     break;   
    case 1:
      switch(id_ic){
      case 0: if(chip5.byteRead(IOCON)==0b00001000) return chip5.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip6.byteRead(IOCON)==0b00001000) return chip6.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip7.byteRead(IOCON)==0b00001000) return chip7.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip8.byteRead(IOCON)==0b00001000) return chip8.digitalRead(id_pin); else return 0;
         break;
      default:
         break;    
    }
    break;
    case 2:
      switch(id_ic){
      case 0: if(chip9.byteRead(IOCON)==0b00001000) return chip9.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip10.byteRead(IOCON)==0b00001000) return chip10.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip11.byteRead(IOCON)==0b00001000) return chip11.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip12.byteRead(IOCON)==0b00001000) return chip12.digitalRead(id_pin); else return 0;
         break;
        default:
         break;    
    }
    break;
    case 3:
      switch(id_ic){
      case 0: if(chip13.byteRead(IOCON)==0b00001000) return chip13.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip14.byteRead(IOCON)==0b00001000) return chip14.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip15.byteRead(IOCON)==0b00001000) return chip15.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip16.byteRead(IOCON)==0b00001000) return chip16.digitalRead(id_pin); else return 0;
         break;   
    
    
        default:
         break;    
    } 
    break;
    case 4:
      switch(id_ic){
      case 0: if(chip17.byteRead(IOCON)==0b00001000) return chip17.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip18.byteRead(IOCON)==0b00001000) return chip18.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip19.byteRead(IOCON)==0b00001000) return chip19.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip20.byteRead(IOCON)==0b00001000) return chip20.digitalRead(id_pin); else return 0;
         break;  
    
    
        default:
         break;    
    } 
    break;
    case 5:
      switch(id_ic){
      case 0: if(chip21.byteRead(IOCON)==0b00001000) return chip21.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip22.byteRead(IOCON)==0b00001000) return chip22.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip23.byteRead(IOCON)==0b00001000) return chip23.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip24.byteRead(IOCON)==0b00001000) return chip24.digitalRead(id_pin); else return 0;
         break;   
    
    
        default:
         break;    
    }
    break;
    case 6:
      switch(id_ic){
      case 0: if(chip25.byteRead(IOCON)==0b00001000) return chip25.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip26.byteRead(IOCON)==0b00001000) return chip26.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip27.byteRead(IOCON)==0b00001000) return chip27.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip28.byteRead(IOCON)==0b00001000) return chip28.digitalRead(id_pin); else return 0;
         break;
    
    
    
        default:
         break;    
    }
    break;
    case 7:
      switch(id_ic){
      case 0: if(chip29.byteRead(IOCON)==0b00001000) return chip29.digitalRead(id_pin); else return 0;
               break;
      case 1: if(chip30.byteRead(IOCON)==0b00001000) return chip30.digitalRead(id_pin); else return 0;
               break;
      case 2: if(chip31.byteRead(IOCON)==0b00001000) return chip31.digitalRead(id_pin); else return 0;
               break;
      case 3: if(chip32.byteRead(IOCON)==0b00001000) return chip32.digitalRead(id_pin); else return 0;
         break;    
    
        default:
         break;    
    }
    break;
    default:
         return 0;break;
  }
}
/**/
void clear_data(){
  for(char i=0;i<32;i++){
      data[i]=0;
      }
}
/**/
bool bcc_check(unsigned char str[]){ 
  unsigned char checksum=0;
  for(int i=0;i<5;i++){
    checksum += str[i];
  }
  if(checksum == str[5])
  {return true; }
  else{return false;}
}
/*return string with  port same level Example: 1=2=3=*/
void check(){
  dem= "";
  for(unsigned int i=0;i<32;i++)
  {
      if(data[i]!=0xffff) for(unsigned int j=0;j<16;j++){if((((~data[i])>>j) & 0x0001)!=0) dem=dem + String(i*16+j+1)+ "=";}   
  }                        
  //return dem;
  }
void check2(){
  dem= "";
  for(unsigned int i=0;i<32;i++)
  {
      if(data[i]!=0xffff) dem=dem+String(i)+"*"+String(~data[i],HEX)+ "=";   
  }                        
  //return dem;
  }
/*save least 2 value in array data_single_port*/
void check_single_port(){
   data_single_port[0]=0;
   data_single_port[1]=0;
   unsigned char k=0;
  for(unsigned char i=0;i<32;i++)
  {
      if(data[i]!=0|k<2) for(unsigned char j=0;j<16;j++){
                                                    if(((data[i]>>j) & 0x0001)!=0){
                                                                                   if(k<2){
                                                                                           data_single_port[k]=i*16+j+1;k+=1;
                                                                                           } else break;
                                                                                   }
                                                    } 
                         else break;
  }
}
void init_interrupts_card(void){
  pinMode(CARD_1,INPUT);
  pinMode(CARD_2,INPUT);
  pinMode(CARD_3,INPUT);
  pinMode(CARD_4,INPUT);
  pinMode(CARD_5,INPUT);
  pinMode(CARD_6,INPUT);
  pinMode(CARD_7,INPUT);
  pinMode(CARD_8,INPUT);
  }

#endif
