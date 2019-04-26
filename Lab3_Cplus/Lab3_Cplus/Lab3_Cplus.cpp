// Lab3_Cplus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <string.h>

void Output(int i, int j, int pointer, char *string, int *array);

int main()
{
	char *string = new char[20];
	char *new_string = new char[20];
	char *pS;

	std::cout << "Enter your string: " << "\n";
	std::cin.getline(string, 20);
	pS = strchr(string, ' ');
	int length = strlen(string);
	std::cout << "length" << length;

	std::cout << "First " << "\t" << pS - string;
	int pointer = 1;

	do
	{
		pS++;
		pS = strchr(pS, ' ');
		std::cout << "\t" << pS - string;
		pointer++;
	} while (pS); // цикл поиска колличества пробелов

	
	std::cout << "\n" << "===========================" << "\n";

	int *array = new int[pointer]; // создаем динамический массив для индексов мест, где находятся пробелы

	pS = strchr(string, ' ');

	array[0] = 0; // индекс начала строки
	array[1] = pS - string; // индекс первого пробела 
	std::cout << "array:" << "\n";
	std::cout << "array 0) " << array[0] << "\n";
	std::cout << "array 1) " << array[1] << "\n";

	for (size_t i = 2; i <= pointer; i++) // начинаем со второго, потому что я вручную присвоил массиву 0 и 1 значения.
	{
		if (pS) // присваеваем остальным элементам массива значения индексов последующих пробелов
		{
			pS++;
			pS = strchr(pS, ' ');
			array[i] = pS - string;
			array[pointer] = length; // отмечаем индекс конца строки
			std::cout << "array " << i << ") " << array[i] << "\n";
		}
		
	}

	for (size_t i = 0; i <= pointer ; i++) // цикл для массива с индексами
	{
		for (size_t j = 0; j < 20; j++) // цикл для проверки символов со строки
		{
			if ((string[j] == string[array[i] - 1]) && (string[j] != '\0'))
			{
				Output(i, j, pointer, string, array);
				continue;
			}
			else if (j == array[i] - 1)
			{
				continue;
			}
		}
	}
}

void Output(int i, int j, int pointer, char *string, int *array) // функция вывода найденых слов
{
	std::cout << "your word:";
	
	for ( j ; j <= array[i] - 1; j++)
	{
		std::cout << string[j];
	}
	std::cout << "\n";
}