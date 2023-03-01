//���� ��������� �������
#ifndef __PROTOTYPES_H
#define __PROTOTYPES_H

//�������� ������� ����������
void interrupt(void);

//�������� ������� ���������� ������ EEPROM
unsigned short initialEEPROMread(void);

//�������� ������� ������ � EEPROM
void EEPROM_write_Func(unsigned short addr, unsigned short dat);

//�������� ������� ��������� ���������� "����"
void Led_Hours_On(void);

//�������� ������� ���������� ���������� "����"
void Led_Hours_Off(void);

//�������� ������� ��������� ���������� "������"
void Led_Minutes_On(void);

//�������� ������� ���������� ���������� "������"
void Led_Minutes_Off(void);

//�������� ������� ��������� ���������� "�������"
void Led_Seconds_On(void);

//�������� ������� ���������� ���������� "�������"
void Led_Seconds_Off(void);

//�������� ������� �������� �����������
void Display_Lamp_Test(void);

//�������� ������� �������� �������� �� �������
void Display_Out(void);

//�������� ������� ��������� ���������� �������� �������
void Dislay_Lo_On(void);

//�������� ������� ���������� ���������� �������� �������
void Dislay_Lo_Off(void);

//�������� ������� ��������� ���������� �������� �������
void Dislay_Hi_On(void);

//�������� ������� ���������� ���������� �������� �������
void Dislay_Hi_Off(void);

//�������� ������� ��������� ����
void Relay_On(void);

//�������� ������� ���������� ����
void Relay_Off(void);

//�������� ������� �������� �������
void MainTimer();

#endif