//Файл глобальных переменных
#ifndef __VARIABLES_H
#define __VARIABLES_H

unsigned short EEPROM_containment = 0;
unsigned short Seconds_On;
unsigned short Seconds_Off;
unsigned short Minutes_On;
unsigned short Minutes_Off;
unsigned short Hours_On;
unsigned short Hours_Off;
unsigned short INTCON_previous_statement;
unsigned short Disp_Data;

unsigned long Time_Hours_On_InSec = 0;
unsigned long Time_Hours_Off_InSec = 0;
unsigned long Time_Minutes_On_InSec = 0;
unsigned long Time_Minutes_Off_InSec = 0;

typedef struct{
	sensor_state : 1;
	display_on : 1;
}mybitfield;

mybitfield ControlBits;

#endif