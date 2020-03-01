#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <string.h>
#include <stdlib.h> 
#define MAXMESSAGESIZE 256

char rusFont[33] = "�������������������������������\0";
typedef char* string;
string cesar(char inputChar[], int inputShift, char rusFont[])
{
	char buffer[2] = "0\0";
	int size = strlen(inputChar); // ����� ���������

	for (int i = 0; i < size; i++) //������ �� ���������� ��������� 
	{
		buffer[0] = inputChar[i]; //������� �������� � �����
		inputChar[i] = rusFont[(strstr(rusFont, buffer) - rusFont + inputShift) % 32]; //������� ���������� ���� ������� i, ���������� � ���� ����� � ������� �� ������
	}
	return inputChar;
}

int main(void)
{
	system("chcp 1251");
	system("cls");
	int inputShift; //���������� ������ (����)
	int size;
	char inputChar[MAXMESSAGESIZE]; //��������� ������������
	printf("\n���������� ����� ������ ��� �������� �����.\n\n������� ���� - ");
	scanf("%d", &inputShift);
	printf("\n������� ��������� ��� ����������: ");
	size = scanf("%s", inputChar); 
	string outputChar = cesar(inputChar, inputShift, rusFont);
	printf("\n");
	printf("������������� ������: "); 
	puts(outputChar);
	printf("\n");
	return 0;
}