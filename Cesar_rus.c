/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : Cesar_rus.c
* Compiler          : Microsoft Visual Studio 2015
* Version           : 14.0.5
* Created File      : 23.02.2020
* Last modified     : 14.03.2020
*
* Support mail      : anton.kravczov.1998@mail.ru
*
* Description       : Realisation of Cesar's encryption for Russian
*                   :
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#define MAXMESSAGESIZE 256
int8_t rusFont[33] = "абвгдеёжзиклмнопрстуфхцчшщъыьэюя\0";
typedef int8_t* string;
string cesar(int8_t inputChar[], int inputShift, int8_t rusFont[])
{
	int8_t buffer[2] = "0\0";
	int size = strlen(inputChar); // длина сообщения
	int8_t *st;
	for (int i = 0; i < size; i++) //проход по введенному сообщению 
	{
		buffer[0] = inputChar[i]; //Заносим значение в буфер
		st = strstr(rusFont, buffer);
		inputChar[i] = rusFont[(st - rusFont + inputShift) % 32]; //разница указателей даст искомый i, прибавляем к нему сдвиг и считаем по модулю
	}
	return inputChar;
}
int main(void)
{
	setlocale(LC_ALL, "");
	int inputShift; //переменная сдвига (ключ)
	int8_t inputChar[MAXMESSAGESIZE]; //сообщение пользователя
	printf("\nРеализация шифра Цезаря для русского языка.\n\nВведите ключ - ");
	scanf("%d", &inputShift);
	printf("\nВведите сообщение для шифрования: ");
	scanf("%s", inputChar);
	string outputChar = cesar(inputChar, inputShift, rusFont);
	printf("\n");
	//fflush(stdout);
	printf("Зашифрованная строка: ");
	puts(outputChar);
	//printf("%s\n", outputChar)
	printf("\n");
	return 0;
}
