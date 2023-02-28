//Τΰιλ ξοπεδελενθι
#ifndef __DEFINES_H
#define __DEFINES_H

const unsigned short EEPROM_alredy_wrote = 1;
const unsigned short EEPROM_not_wrote = 2;
const unsigned short Seconds_On_EE_Adr = 0x01;
const unsigned short Seconds_Off_EE_Adr = 0x02;
const unsigned short Minutes_On_EE_Adr = 0x03;
const unsigned short Minutes_Off_EE_Adr = 0x04;
const unsigned short Hours_On_EE_Adr = 0x05;
const unsigned short Hours_Off_EE_Adr=  0x06;
const unsigned short Disp_Mask = 0x0F;
const unsigned short Disp_Mask_Anodes = 0b00001100;

#endif