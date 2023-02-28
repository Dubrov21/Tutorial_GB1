//Функция включения светодиода "Часы"
void Led_Hours_On(void){
   PORTD.F5 = 1;
}

//Функция выключения светодиода "Часы"
void Led_Hours_Off(void){
   PORTD.F5 = 0;
}

//Функция включения светодиода "Минуты"
void Led_Minutes_On(void){
   PORTD.F6 = 1;
}

//Функция выключения светодиода "Минуты"
void Led_Minutes_Off(void){
   PORTD.F6 = 0;
}

//Функция включения светодиода "Секунды"
void Led_Seconds_On(void){
   PORTD.F7 = 1;
}

//Функция выключения светодиода "Секунды"
void Led_Seconds_Off(void){
   PORTD.F7 = 0;
}

//Функция проверки индикаторов
void Display_Lamp_Test(void){
   INTCON.GIE = 0;
   //Проверка светодиодов
   PORTD.F5 = 1;
   PORTD.F6 = 1;
   PORTD.F7 = 1;
   Delay_ms(500);
   PORTD.F5 = 0;
   PORTD.F6 = 0;
   PORTD.F7 = 0;
   //Проверка дисплея
   PORTB = 0b0;        //подали на ключи анодов дисплея минус
   PORTD.F4 = 0;       //подали на вход LT 7447 минус
   Delay_ms(500);
   PORTB = 0b00001100; //подали на ключи анодов дисплея плюс
   PORTD.F4 = 1;       //подали на вход LT 7447 плюс
   INTCON.GIE = 1;
}