//���� ����������

 void interrupt(void)
{
    if(PIR1.TMR1IF)        //If Timer1 Interrupt
    {
		PIR1.TMR1IF = 0;    // clear the interrupt, ��� 25
    }
    
    else if(INTCON.INTF)    //���� ���������� �� ����� INT
    {
		INTCON.INTF = 0;
    }
    
    else if(INTCON.T0IF)    //���� ���������� �� TMR0, ����� �� ����������
    {

		INTCON.T0IF = 0;
    }
    
    else if(INTCON.RBIF)    //���� ���������� �� ������ ����� PORTB
    {
       INTCON.RBIF = 0;
    }
        
    else if(PIR2.EEIF)      //���� ���������� �� EEPROM
    {
       PIR2.EEIF = 0;
    }
}