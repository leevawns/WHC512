/*
  MCP23017.h  Version 0.1
  Microchip MCP23017 I2C I/O Expander Class for Arduino
  follow library Created by Cort Buffington & Keith Neufeld for MCP23S17 ISP
  created by levanlap
  6/2018
*/
#include <Wire.h>                 // Arduino IDE SPI library - uses AVR hardware SPI features
#include "MCP23017.h"            // Header files for this class

// Defines to keep logical information symbolic go here

#ifndef HIGH
#define    HIGH          (1)
#endif

#ifndef LOW
#define    LOW           (0)
#endif

#ifndef ON
#define    ON            (1)
#endif

#ifndef OFF
#define    OFF           (0)
#endif
// find version arduino
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
// minihelper to keep Arduino backward compatibility
static inline void wiresend(uint8_t x) {
#if ARDUINO >= 100
  Wire.write((uint8_t) x);
#else
  Wire.send(x);
#endif
}
static inline uint8_t wirerecv(void) {
#if ARDUINO >= 100
  return Wire.read();
#else
  return Wire.receive();
#endif
}
#define    MCP23017_OPCODEW       (0b00100000)  // Opcode for MCP23S17 with LSB (bit0) set to write (0), address OR'd in later, bits 1-3
#define    MCP23017_OPCODER       (0b01000001)  // Opcode for MCP23S17 with LSB (bit0) set to read (1), address OR'd in later, bits 1-3
#define    MCP23017_ADDR_ENABLE   (0b00001000)  // Configuration register for MCP23S17, the only thing we change is enabling hardware addressing
#define    MCP23017_ADDRESS        0x20
// Constructor to instantiate an instance of MCP to a specific chip (address)
/**
 * Reads a given register
 */
uint8_t MCP23017::byteRead(uint8_t addr){
  // read the current GPINTEN
  Wire.beginTransmission(MCP23017_ADDRESS | _address);
  wiresend(addr);
  Wire.endTransmission();
  Wire.requestFrom(MCP23017_ADDRESS | _address, 1);
  return wirerecv();
}
unsigned int MCP23017::wordRead(uint8_t add) {       // This function will read all 16 bits of I/O, and return them as a word in the format 0x(portB)(portA)
  uint16_t value = 0;                   // Initialize a variable to hold the read values to be returned
  Wire.beginTransmission(MCP23017_ADDRESS | _address);
  wiresend(add);
  Wire.endTransmission();
  
  Wire.requestFrom(MCP23017_ADDRESS | _address, 2);
  value |= (wirerecv()<<8);         // Send any byte, the function will return the read value (register address pointer will auto-increment after write)
  value |= wirerecv();              // Read in the "high byte" (portA) and shift it up to the high location and merge with the "low byte"
  return value;                     // Return the constructed word, the format is 0x(portA)(portB)
}
/**
 * Writes a given register
 */
void MCP23017::byteWrite(uint8_t regAddr, uint8_t regValue){
  // Write the register
  Wire.beginTransmission(MCP23017_ADDRESS | _address);
  wiresend(regAddr);
  wiresend(regValue);
  Wire.endTransmission();
}
// GENERIC WORD WRITE - will write a word to a register pair, LSB to first register, MSB to next higher value register 
void MCP23017::wordWrite(uint8_t reg, uint16_t word_) {  // Accept the start register and word 
  Wire.beginTransmission(MCP23017_ADDRESS| _address);
  wiresend(reg);
  wiresend(word_ & 0xFF);
  wiresend(word_ >> 8);
  Wire.endTransmission();
}
MCP23017::MCP23017(uint8_t address) {
  _address     = constrain(address, 0, 7);
  _modeCache   = 0xFFFF;                // Default I/O mode is all input, 0xFFFF
  _outputCache = 0x0000;                // Default output state is all off, 0x0000
  _pullupCache = 0x0000;                // Default pull-up state is all off, 0x0000
  _invertCache = 0x0000;                // Default input inversion state is not inverted, 0x0000
}
void MCP23017::begin() {
  Wire.begin();
  // set defaults!
  // all inputs on port A and B
  wordWrite(MCP23017_IODIRA,0xffff); // SETTING DIR A B: INPUT MODE
  wordWrite(MCP23017_DEFVALA,0xffff);// SETTING DEFVAL value FOR A B
  wordWrite(MCP23017_INTCONA,0xffff);// SETTING INTERRUPTS CONFIG A B: USE COMPARE WITH DEFVAL
  setupInterrupts(false,false,LOW);  // SETTING INTERRUPTS: NO MICRO, NO OPEN DRAIN, ACTI LOW LEVEL
  enableInterrupt();                 // ENABLE INT
}
// MODE SETTING FUNCTIONS - BY PIN AND BY WORD

void MCP23017::pinMode(uint8_t pin, uint8_t mode_) {  // Accept the pin # and I/O mode
  if (pin < 1 | pin > 16) return;               // If the pin value is not valid (1-16) return, do nothing and return
  if (mode_ == INPUT) {                          // Determine the mode before changing the bit state in the mode cache
    _modeCache |= 1 << (pin - 1);               // Since input = "HIGH", OR in a 1 in the appropriate place
  } else {
    _modeCache &= ~(1 << (pin - 1));            // If not, the mode must be output, so and in a 0 in the appropriate place
  }
  wordWrite(MCP23017_IODIRA, _modeCache);                // Call the generic word writer with start register and the mode cache
}

void MCP23017::pinMode(unsigned int mode_) {     // Accept the word…
  wordWrite(MCP23017_IODIRA, ~mode_);                // Call the the generic word writer with start register and the mode cache
  _modeCache = ~mode_;
}
// THE FOLLOWING WRITE FUNCTIONS ARE NEARLY IDENTICAL TO THE FIRST AND ARE NOT INDIVIDUALLY COMMENTED

// WEAK PULL-UP SETTING FUNCTIONS - BY WORD AND BY PIN
void MCP23017::pullupMode(uint8_t pin, uint8_t mode_) {
  if (pin < 1 | pin > 16) return;
  if (mode_ == ON) {
    _pullupCache |= 1 << (pin - 1);
  } else {
    _pullupCache &= ~(1 << (pin -1));
  }
  wordWrite(MCP23017_GPPUA, _pullupCache);
}


void MCP23017::pullupMode(unsigned int mode_) { 
  wordWrite(MCP23017_GPPUA, mode_);
  _pullupCache = mode_;
}
// INPUT INVERSION SETTING FUNCTIONS - BY WORD AND BY PIN

void MCP23017::inputInvert(uint8_t pin, uint8_t mode_) {
  if (pin < 1 | pin > 16) return;
  if (mode_ == ON) {
    _invertCache |= 1 << (pin - 1);
  } else {
    _invertCache &= ~(1 << (pin - 1));
  }
  wordWrite(MCP23017_IPOLA, _invertCache);
}

void MCP23017::inputInvert(unsigned int mode_) { 
  wordWrite(MCP23017_IPOLA, mode_);
  _invertCache = mode_;
}
void MCP23017::digitalWrite(uint8_t pin, uint8_t value) {
  if (pin < 1 | pin > 16) return;
  if (value) {
    _outputCache |= 1 << (pin - 1);
  } else {
    _outputCache &= ~(1 << (pin - 1));
  }
  wordWrite(MCP23017_GPIOA, _outputCache);
}

void MCP23017::digitalWrite(unsigned int value) { 
  wordWrite(MCP23017_GPIOA, value);
  _outputCache = value;
}
// READ FUNCTIONS - BY WORD, BYTE AND BY PIN

unsigned int MCP23017::digitalRead(void) {       // This function will read all 16 bits of I/O, and return them as a word in the format 0x(portB)(portA)
  uint16_t value = 0;                   // Initialize a variable to hold the read values to be returned
  Wire.beginTransmission(MCP23017_ADDRESS | _address);
  wiresend(MCP23017_GPIOA);
  Wire.endTransmission();
  
  Wire.requestFrom(MCP23017_ADDRESS | _address, 2);
  value |= (wirerecv()<<8);         // Send any byte, the function will return the read value (register address pointer will auto-increment after write)
  value |= wirerecv();              // Read in the "high byte" (portA) and shift it up to the high location and merge with the "low byte"
  return value;                     // Return the constructed word, the format is 0x(portA)(portB)
}
uint8_t MCP23017::digitalRead(uint8_t pin) {                    // Return a single bit value, supply the necessary bit (1-16)
    if (pin < 1 | pin > 16) return 0x0;        // If the pin value is not valid (1-16) return, do nothing and return
    return digitalRead() & (1 << (pin-1)) ? HIGH : LOW;  // Call the word reading function, extract HIGH/LOW information from the requested pin
}
/**
 * Configures the interrupt system. both port A and B are assigned the same configuration.
 * Mirroring will OR both INTA and INTB pins.
 * Opendrain will set the INT pin to value or open drain.
 * polarity will set LOW or HIGH on interrupt.
 * Default values after Power On Reset are: (false,flase, LOW)
 * If you are connecting the INTA/B pin to arduino 2/3, you should configure the interupt handling as FALLING with
 * the default configuration.
 */
void MCP23017::setupInterrupts(uint8_t mirroring, uint8_t openDrain,uint8_t polarity){
  // configure the port A
  uint8_t ioconfValue=byteRead(MCP23017_IOCONA);
  bitWrite(ioconfValue,6,mirroring);
  bitWrite(ioconfValue,2,openDrain);
  bitWrite(ioconfValue,1,polarity);
  byteWrite(MCP23017_IOCONA,ioconfValue);
  
  ioconfValue=byteRead(MCP23017_IOCONB);
  bitWrite(ioconfValue,6,mirroring);
  bitWrite(ioconfValue,2,openDrain);
  bitWrite(ioconfValue,1,polarity);
  byteWrite(MCP23017_IOCONB,ioconfValue);
}
void MCP23017::enableInterrupt(void){
  wordWrite(MCP23017_GPINTENA,0xffff);
  }
void MCP23017::disableInterrupt(void){
  wordWrite(MCP23017_GPINTENA,0x0000);
  }
/**
 * Set's up a pin for interrupt. uses arduino MODEs: CHANGE, FALLING, RISING.
 *
 * Note that the interrupt condition finishes when you read the information about the port / value
 * that caused the interrupt or you read the port itself. Check the datasheet can be confusing.
 *
 */
 /*
void MCP23017::setupInterruptPin(uint8_t pin, uint8_t mode) {

  // set the pin interrupt control (0 means change, 1 means compare against given value);
  updateRegisterBit(pin,(mode!=CHANGE),MCP23017_INTCONA,MCP23017_INTCONB);
  // if the mode is not CHANGE, we need to set up a default value, different value triggers interrupt

  // In a RISING interrupt the default value is 0, interrupt is triggered when the pin goes to 1.
  // In a FALLING interrupt the default value is 1, interrupt is triggered when pin goes to 0.
  updateRegisterBit(pin,(mode==FALLING),MCP23017_DEFVALA,MCP23017_DEFVALB);

  // enable the pin for interrupt
  updateRegisterBit(pin,HIGH,MCP23017_GPINTENA,MCP23017_GPINTENB);

}

uint8_t MCP23017::getLastInterruptPin(){
  uint8_t intf;

  // try port A
  intf=readRegister(MCP23017_INTFA);
  for(int i=0;i<8;i++) if (bitRead(intf,i)) return i;

  // try port B
  intf=readRegister(MCP23017_INTFB);
  for(int i=0;i<8;i++) if (bitRead(intf,i)) return i+8;

  return MCP23017_INT_ERR;

}
uint8_t MCP23017::getLastInterruptPinValue(){
  uint8_t intPin=getLastInterruptPin();
  if(intPin!=MCP23017_INT_ERR){
    uint8_t intcapreg=regForPin(intPin,MCP23017_INTCAPA,MCP23017_INTCAPB);
    uint8_t bit=bitForPin(intPin);
    return (readRegister(intcapreg)>>bit) & (0x01);
  }

  return MCP23017_INT_ERR;
}*/
