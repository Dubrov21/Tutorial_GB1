//������� ��������� ���������� "����"
void Led_Hours_On(void){
   PORTD.F5 = 1;
}

//������� ���������� ���������� "����"
void Led_Hours_Off(void){
   PORTD.F5 = 0;
}

//������� ��������� ���������� "������"
void Led_Minutes_On(void){
   PORTD.F6 = 1;
}

//������� ���������� ���������� "������"
void Led_Minutes_Off(void){
   PORTD.F6 = 0;
}

//������� ��������� ���������� "�������"
void Led_Seconds_On(void){
   PORTD.F7 = 1;
}

//������� ���������� ���������� "�������"
void Led_Seconds_Off(void){
   PORTD.F7 = 0;
}

//������� �������� �����������
void Display_Lamp_Test(void){
   INTCON.GIE = 0;
   //�������� �����������
   PORTD.F5 = 1;
   PORTD.F6 = 1;
   PORTD.F7 = 1;
   Delay_ms(500);
   PORTD.F5 = 0;
   PORTD.F6 = 0;
   PORTD.F7 = 0;
   //�������� �������
   PORTB = 0b0;        //������ �� ����� ������ ������� �����
   PORTD.F4 = 0;       //������ �� ���� LT 7447 �����
   Delay_ms(500);
   PORTB = 0b00001100; //������ �� ����� ������ ������� ����
   PORTD.F4 = 1;       //������ �� ���� LT 7447 ����
   INTCON.GIE = 1;
}