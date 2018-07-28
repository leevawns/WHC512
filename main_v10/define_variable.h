/**********************************************************************************
 *      THU VIEN KHAI BAO BIEN 
 *********************************************************************************/
#ifndef _define_variable_h
#define _define_variable_h

#include "MCP23S17.h"
#include "MCP23017.h"
#include <arduino.h>

/* Khai bao ngoai vi ----------------------------------------------------------*/
uint8_t BUZZER = 4;
uint8_t SEARCH_EN = 3;
uint8_t LED = 2;
uint8_t TAPE = 6;
//-------------------
/*var for serial community*/
unsigned char inputChar[6];         // a string to hold incoming data
unsigned char outputChar[4];         // a string to hold outcoming data
unsigned char outputCharOk[4]={'O','\0','\0','O'};         // a string to hold outcoming data
boolean stringComplete = false;  // whether the string is complete
/*******************************************/
String dem= "";
String sr=""; //var for search pin
unsigned long time_=0; //var for test timing
//-----------------------------------------------------------------------
unsigned int data[32];// 512 BIT = 512 PORT, FROM 1-512, 1 DATA = 16 BIT
unsigned int data_single_port[2];// 2 port in single check
byte test_chip[32];// KIEM TRA KET NOI CAC CHIP. O: DISCONNECT, 1: CONNECT
bool readport_1;
bool readport_2;
//*************************************************************************
unsigned int id_card;
unsigned int id_ic;
unsigned int id_pin;
unsigned int data_in=0;
unsigned int port_1=0;
unsigned int port_2=0;
/* Khai bao chan chon card --------------------------------------------------- */
uint8_t SS1 = 22, SS2 = 23, SS3 = 24, SS4 = 25, SS5 = 26, SS6 = 27, SS7 = 28, SS8 = 29;
/* Khai bao chip MCP23S17 ----------------------------------------------------*/
MCP chip1 (0,SS1);    // Card1
MCP chip2 (1,SS1);    // Card1
MCP chip3 (2,SS1);    // Card1
MCP chip4 (3,SS1);    // Card1

MCP chip5 (0,SS2);    // Card2
MCP chip6 (1,SS2);    // Card2
MCP chip7 (2,SS2);    // Card2
MCP chip8 (3,SS2);    // Card2

MCP chip9 (0,SS3);    // Card3
MCP chip10 (1,SS3);   // Card3
MCP chip11 (2,SS3);   // Card3
MCP chip12 (3,SS3);   // Card3

MCP chip13 (0,SS4);   // Card4
MCP chip14 (1,SS4);   // Card4
MCP chip15 (2,SS4);   // Card4
MCP chip16 (3,SS4);   // Card4

MCP chip17 (0,SS5);   // Card5
MCP chip18 (1,SS5);   // Card5
MCP chip19 (2,SS5);   // Card5
MCP chip20 (3,SS5);   // Card5

MCP chip21 (0,SS6);   // Card6
MCP chip22 (1,SS6);   // Card6
MCP chip23 (2,SS6);   // Card6
MCP chip24 (3,SS6);   // Card6

MCP chip25 (0,SS7);   // Card7
MCP chip26 (1,SS7);   // Card7
MCP chip27 (2,SS7);   // Card7
MCP chip28 (3,SS7);   // Card7

MCP chip29 (0,SS8);   // Card8
MCP chip30 (1,SS8);   // Card8
MCP chip31 (2,SS8);   // Card8
MCP chip32 (3,SS8);   // Card8
/*MCP23017---INTERRUPTS CARD-----------------------------------*/
uint8_t CARD_2=48,CARD_1=13,CARD_4=46,CARD_3=47,CARD_6=44,CARD_5=45,CARD_8=42,CARD_7=43;
/*khoi tao class MCP23017---------------------------*/
MCP23017 chip_sub_1(0);
MCP23017 chip_sub_2(1);
MCP23017 chip_sub_3(2);
MCP23017 chip_sub_4(3);
/*begin---------------------------*/
#endif
