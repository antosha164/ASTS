/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : cesar.c
* Compiler          : NetBeans
* Version           : 8.2
* Created File      : 25.05.2020
* Last modified     : 01.06.2020
*
* Support mail      : anton.kravczov.1998@mail.ru
*
* Description       : Realisation of Cesar's encryption for English
*******************************************************************************/
#include "main.h" 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <stdint.h>
#include "mstn_clk.h" 
#include "mstn_led.h" 
#include "mstn_adc.h" 
#include "mstn_button.h" 
#include "mstn_usb.h" 
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

int main(int argc, char *argv[]) 
{
    int inputShift = 3; //переменная сдвига (ключ)
    int8_t inputChar[MAXMESSAGESIZE] = "tusur"; //сообщение пользователя
    BTN_UserButtonInit();
    while(1) 
    {
        if ((BTN_UserButtonRead() == PRESSED))
        {
            string outputChar = cesar(inputChar, inputShift, engFont);
            printf("\n");
            printf("Encrypting message: ");
            puts(outputChar);
            printf("\n");
            for (int i=0;i<inputShift;++i){
            LED_SetGreenState(TURN_ON); 
            Delay (1000); 
            LED_SetGreenState(TURN_OFF); 
            Delay (1000);
            }
            for (int i=0;i<inputShift;++i){
            LED_SetRedState(TURN_ON); 
            Delay (1000); 
            LED_SetRedState(TURN_OFF); 
            Delay (1000);
            }
        }   
    }
return EXIT_SUCCESS; 
}
