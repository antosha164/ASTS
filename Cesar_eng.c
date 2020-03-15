/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : Cesar_eng.c
* Compiler          : Microsoft Visual Studio 2015
* Version           : 14.0.5
* Created File      : 23.02.2020
* Last modified     : 14.03.2020
*
* Support mail      : anton.kravczov.1998@mail.ru
*
* Description       : Realisation of Cesar's encryption for English
*                   :
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdint.h>
#define MAXMESSAGESIZE 256

int8_t engFont[33] = "abcdefghijklmnopqrstuvwxyz\0";
typedef int8_t* string;
string cesar(int8_t inputChar[], int inputShift, int8_t engFont[])
{
	int8_t buffer[2] = "0\0";
	int size = strlen(inputChar); // длина сообщения
	int8_t *st;
	for (int i = 0; i < size; i++) //проход по введенному сообщению 
	{
		buffer[0] = inputChar[i];//Заносим значение в буфер
		st = strstr(engFont, buffer);
		inputChar[i] = engFont[(st - engFont + inputShift) % 25]; //разница указателей даст искомый i, прибавляем к нему сдвиг и считаем по модулю
	}
	return inputChar;
}

int main(void)
{
	int inputShift; //переменная сдвига (ключ)
	int8_t inputChar[MAXMESSAGESIZE]; //сообщение пользователя
	printf("\nRealisation of Cesar's encryption for English.\n\nEnter key - ");
	scanf("%d", &inputShift);
	printf("\nEnter a message for encrypting: ");
	scanf("%s", inputChar);
	string outputChar = cesar(inputChar, inputShift, engFont);
	printf("\n");
	printf("Encrypting message: ");
	puts(outputChar);
	printf("\n");
	return 0;
}