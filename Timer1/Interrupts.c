//Файл прерываний

 void interrupt(void)
{
    if(PIR1.TMR1IF)        //If Timer1 Interrupt
    {
		PIR1.TMR1IF = 0;    // clear the interrupt, стр 25
    }
    
    else if(INTCON.INTF)    //Если прерывание от входа INT
    {
		INTCON.INTF = 0;
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