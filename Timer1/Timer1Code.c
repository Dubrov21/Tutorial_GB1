/*  Name     :
 *  Purpose  : Main file for using timer1 of PIC16F877.
 *  Author   :
 *  Date     :
 *  Website  :
 *  Revision : None
 */

#include "variables.h"
#include "defines.h"
#include "prototypes.h"

void interrupt(void)
{
    if(PIR1.TMR1IF)        //If Timer1 Interrupt
    {
		PIR1.TMR1IF = 0;    // clear the interrupt, стр 25
    }

    else if(INTCON.INTF)    //Если прерывание от входа INT
    {   //если прерывание от входа датчика, перезапустить основной таймер
		INTCON.INTF = 0;
        ControlBits.sensor_state = 1;
    }

    else if(INTCON.T0IF)    //Если прерывание от TMR0, вывод на индикаторы
    {

		INTCON.T0IF = 0;
    }

    else if(INTCON.RBIF)    //Если прерывание от входов порта PORTB
    {
		INTCON.RBIF = 0;
    }

    else if(PIR2.EEIF)      //Если прерывание от EEPROM
    {
		PIR2.EEIF = 0;
    }
}

//Функция записи в EEPROM
void EEPROM_write_Func(unsigned short addr, unsigned short dat){
        INTCON_previous_statement = INTCON;
        EEPROM_Write(addr, dat);
//Разрешаем глобальные прерывания и прерывания от периферийных модулей
//остальные прерывания запрещены
        INTCON = 0b11000000;
        while(PIR2.EEIF != 1)   //ждем прерывания от EEPROM
        PIR2.EEIF = 0;
        INTCON = INTCON_previous_statement;
}

//Функция инициализации TMR1
void InitTimer1(void)
{
        TMR1H = 0;                       // Cleat timer1 registers
        TMR1L = 0;                       // before enabling timer1

        // Timer1 is 16bit timer
        T1CON = 0b00001111;              // Prescalar 1:1, Timer1 On

        PIR1.TMR1IF = 0;                 // Clear interrupt flag
        PIE1.TMR1IE = 1;                 // Enable Timer1 interrupt
        INTCON.PEIE = 1;                 // Enable peripheral interrupts
        INTCON.GIE = 1;                  // Enable global interrupts
}

//Функция первичного опроса состояния EEPROM
unsigned short initialEEPROMread()
{
    unsigned short containment;
    containment = Eeprom_Read(0x00);
    if (containment = 0xAA) return EEPROM_alredy_wrote;
    else return EEPROM_not_wrote;
}

void MainTimer(){
    //получение значений интервалов времени из EEPROM
    //1 час = 3600 с
    Seconds_On = Eeprom_Read(Seconds_On_EE_Adr);
    Seconds_Off = Eeprom_Read(Seconds_Off_EE_Adr);
    Minutes_On = Eeprom_Read(Minutes_On_EE_Adr);
    Minutes_Off = Eeprom_Read(Minutes_Off_EE_Adr);
    Hours_On = Eeprom_Read(Hours_On_EE_Adr);
    Hours_Off = Eeprom_Read(Hours_Off_EE_Adr);
    
    INTCON.GIE = 0;
        //Расчет времени включения нагрузки в секундах
    Time_Hours_On_InSec = Hours_On * 3600;
    Time_Hours_Off_InSec = Hours_Off * 3600;
    Time_Minutes_On_InSec = Minutes_On * 60;
    Time_Minutes_Off_InSec = Minutes_Off * 60;
    INTCON.GIE = 1;
    
    ControlBits.display_on = 0;;   //Включили индикатор 0
    ControlBits.sensor_state = 0;   //Срабатывания датчика небыло
    
        while(1)
        {

        }
}

// Main Function
void main(void)
{
     //Подтягивающие резисторы PORTB вкл, тактовый сигнал для TMR0 - внутр,
     //предделитель перед TMR0, коэффициент деления предделителя - 1:256
     OPTION_REG = 0b01000111;
     INTCON = 0b01110000;
     //
     TRISB = 0b11110001;    //
     PORTB = 0x0;           //
     
     TRISD = 0xFF;
     PORTD = 0x0;
     PIE2 = 0b00010000;    //Разрешаем прерывания от EEPROM, стр 26
     
     //Запрос первичной информации о том, что в EEPROM записаны интервалы времени
     EEPROM_containment = initialEEPROMread();
     if (EEPROM_containment == EEPROM_not_wrote)
        {
          EEPROM_write_Func(0x00, 0xAA);
          // Запись первичных данных об интервалах времени
          Seconds_On = 5;
          Seconds_Off = 5;
          Minutes_On = 0;
          Minutes_Off = 0;
          Hours_On = 0;
          Hours_Off = 0;
          EEPROM_write_Func(Seconds_On_EE_Adr, Seconds_On);
          EEPROM_write_Func(Seconds_Off_EE_Adr, Seconds_Off);
          EEPROM_write_Func(Minutes_On_EE_Adr, Minutes_On);
          EEPROM_write_Func(Minutes_Off_EE_Adr, Minutes_Off);
          EEPROM_write_Func(Hours_On_EE_Adr, Hours_On);
          EEPROM_write_Func(Hours_Off_EE_Adr, Hours_Off);
        }

          Display_Lamp_Test();  //Проверка светодиодов и дисплея
          InitTimer1();         //Initialize timer 1
          MainTimer();          //Вызов функции основного таймера
          
}