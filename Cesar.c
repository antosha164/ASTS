#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAXMESSAGESIZE 256

char rusFont[33] = "абвгдеёжзиклмнопрстуфхцчшщъыьэюя\0";
typedef char* string;
string cesar(char inputChar[], int inputShift, char rusFont[])
{
	char buffer[2] = "0\0";
	int size = strlen(inputChar); // длина сообщения

	for (int i = 0; i < size; i++) //проход по введенному сообщению 
	{
		buffer[0] = inputChar[i]; //Заносим значение в буфер
		inputChar[i] = rusFont[(strstr(rusFont, buffer) - rusFont + inputShift) % 32]; //разница указателей даст искомый i, прибавляем к нему сдвиг и считаем по модулю
	}
	return inputChar;
}

int main(void)
{
	system("chcp 1251");
	system("cls");
	int inputShift; //переменная сдвига (ключ)
	int size;
	char inputChar[MAXMESSAGESIZE]; //сообщение пользователя
	printf("\nРеализация шифра Цезаря для русского языка.\n\nВведите ключ - ");
	scanf("%d", &inputShift);
	printf("\nВведите сообщение для шифрования: ");
	size = scanf("%s", inputChar); 
	string outputChar = cesar(inputChar, inputShift, rusFont);
	printf("\n");
	printf("Зашифрованная строка: "); 
	puts(outputChar);
	printf("\n");
	return 0;
}
