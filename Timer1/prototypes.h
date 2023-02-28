//Файл проотипов функций
#ifndef __PROTOTYPES_H
#define __PROTOTYPES_H

//Прототип функции прерывания
void interrupt(void);

//Прототип функции первичного опроса EEPROM
unsigned short initialEEPROMread(void);

//Прототип функции записи в EEPROM
void EEPROM_write_Func(unsigned short addr, unsigned short dat);

//Прототип функции включения светодиода "Часы"
void Led_Hours_On(void);

//Прототип функции выключения светодиода "Часы"
void Led_Hours_Off(void);

//Прототип функции включения светодиода "Минуты"
void Led_Minutes_On(void);

//Прототип функции выключения светодиода "Минуты"
void Led_Minutes_Off(void);

//Прототип функции включения светодиода "Секунды"
void Led_Seconds_On(void);

//Прототип функции выключения светодиода "Секунды"
void Led_Seconds_Off(void);

//Прототип функции проверки индикаторов
void Display_Lamp_Test(void);

//Прототип функции передачи значений на дисплей
void Display_Out(void);

//Прототип функции включения индикатора младшего разряда
void Dislay_Lo_On(void);

//Прототип функции выключения индикатора младшего разряда
void Dislay_Lo_Off(void);

//Прототип функции включения индикатора старшего разряда
void Dislay_Hi_On(void);

//Прототип функции выключения индикатора старшего разряда
void Dislay_Hi_Off(void);

//Прототип функции включения реле
void Relay_On(void);

//Прототип функции выключения реле
void Relay_Off(void);

//Прототип функции главного таймера
void MainTimer();

#endif