/*
  MCP23017.h  Version 0.1
  Microchip MCP23017 I2C I/O Expander Class for Arduino
  follow library Created by Cort Buffington & Keith Neufeld for MCP23S17 ISP
  created by levanlap
  6/2018
*/
 
#ifndef MCP23017_h
#define MCP23017_h
// REGISTERS ARE DEFINED HERE SO THAT THEY MAY BE USED IN THE MAIN PROGRAM

#define    MCP23017_IODIRA    (0x00)      // MCP23x17 I/O Direction Register
#define    MCP23017_IODIRB    (0x01)      // 1 = Input (default), 0 = Output

#define    MCP23017_IPOLA     (0x02)      // MCP23x17 Input Polarity Register
#define    MCP23017_IPOLB     (0x03)      // 0 = Normal (default)(low reads as 0), 1 = Inverted (low reads as 1)

#define    MCP23017_GPINTENA  (0x04)      // MCP23x17 Interrupt on Change Pin Assignements
#define    MCP23017_GPINTENB  (0x05)      // 0 = No Interrupt on Change (default), 1 = Interrupt on Change

#define    MCP23017_DEFVALA   (0x06)      // MCP23x17 Default Compare Register for Interrupt on Change
#define    MCP23017_DEFVALB   (0x07)      // Opposite of what is here will trigger an interrupt (default = 0)

#define    MCP23017_INTCONA   (0x08)      // MCP23x17 Interrupt on Change Control Register
#define    MCP23017_INTCONB   (0x09)      // 1 = pin is compared to DEFVAL, 0 = pin is compared to previous state (default)

#define    MCP23017_IOCONA     (0x0A)      // MCP23x17 Configuration Register
#define    MCP23017_IOCONB     (0x0B)      // MCP23x17 Configuration Register
//                   (0x0B)      //     Also Configuration Register

#define    MCP23017_GPPUA     (0x0C)      // MCP23x17 Weak Pull-Up Resistor Register
#define    MCP23017_GPPUB     (0x0D)      // INPUT ONLY: 0 = No Internal 100k Pull-Up (default) 1 = Internal 100k Pull-Up 

#define    MCP23017_INTFA     (0x0E)      // MCP23x17 Interrupt Flag Register
#define    MCP23017_INTFB     (0x0F)      // READ ONLY: 1 = This Pin Triggered the Interrupt

#define    MCP23017_INTCAPA   (0x10)      // MCP23x17 Interrupt Captured Value for Port Register
#define    MCP23017_INTCAPB   (0x11)      // READ ONLY: State of the Pin at the Time the Interrupt Occurred

#define    MCP23017_GPIOA     (0x12)      // MCP23x17 GPIO Port Register
#define    MCP23017_GPIOB     (0x13)      // Value on the Port - Writing Sets Bits in the Output Latch

#define    MCP23017_OLATA     (0x14)      // MCP23x17 Output Latch Register
#define    MCP23017_OLATB     (0x15)      // 1 = Latch High, 0 = Latch Low (default) Reading Returns Latch State, Not Port Value!

#include <Arduino.h>
class MCP23017 {
  public:
    MCP23017(uint8_t);                   // Constructor to instantiate a discrete IC as an object, address 0-7, chipSelect any valid pin
    void begin();                            // Start the SPI Bus
    void wordWrite(uint8_t, uint16_t);   // Typically only used internally, but allows the user to write any register pair if needed, so it's public
    void byteWrite(uint8_t, uint8_t);        // Typically only used internally, but allows the user to write any register if needed, so it's public
    void pinMode(uint8_t, uint8_t);          // Sets the mode (input or output) of a single I/O pin
    void pinMode(uint16_t);              // Sets the mode (input or output) of all I/O pins at once 
    void pullupMode(uint8_t, uint8_t);       // Selects internal 100k input pull-up of a single I/O pin
    void pullupMode(uint16_t);           // Selects internal 100k input pull-up of all I/O pins at once
    void inputInvert(uint8_t, uint8_t);      // Selects input state inversion of a single I/O pin (writing 1 turns on inversion) 
    void inputInvert(uint16_t);          // Selects input state inversion of all I/O pins at once (writing a 1 turns on inversion)
    void digitalWrite(uint8_t, uint8_t);     // Sets an individual output pin HIGH or LOW
    void digitalWrite(uint16_t);         // Sets all output pins at once. If some pins are configured as input, those bits will be ignored on write
    uint8_t digitalRead(uint8_t);            // Reads an individual input pin
    uint8_t byteRead(uint8_t);               // Reads an individual register and returns the byte. Argument is the register address
    uint16_t wordRead(uint8_t);
    unsigned int digitalRead(void);          // Reads all input  pins at once. Be sure it ignore the value of pins configured as output!
    void setupInterrupts(uint8_t, uint8_t, uint8_t);//setting interrupts
    void enableInterrupt(void);             //enable interrupt
    void disableInterrupt(void);            //disable interrupt
  private:
    uint8_t _address;                   // Address of the MCP23S17 in use
    uint16_t _modeCache;                 // Caches the mode (input/output) configuration of I/O pins
    uint16_t _pullupCache;               // Caches the internal pull-up configuration of input pins (values persist across mode changes)
    uint16_t _invertCache;               // Caches the input pin inversion selection (values persist across mode changes)
    uint16_t _outputCache;               // Caches the output pin state of pins
 };
		
#endif //MCP23017
