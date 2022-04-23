// Привет Мир.cpp
//

#include <iostream>
#include <locale>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");	//Подключили русский язык
    std::cout << "Привет Мир!\n";
	return 0;
}

