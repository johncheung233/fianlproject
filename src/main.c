#include "LPC11xx.h"                    // Device header
#include "ADC.h"
#include "BREAK.h"
#include "lcd.h"
#include "UART.h"
#include <stdio.h>
#include <string.h>
#define UART_BPS 115200

 


 uint32_t i;
 uint32_t ulADCData;
 uint32_t ulADCBuf;
int main()
{

	extern uint8_t SETTEMP;
	extern char LEDBuffer[20];
	char GcRcvBuf[20];
	BreakInit();
	KEYinit();
	SEGinit();
	InitLCD();
	LCD_IOInit();
	UART_Init();
	while(1)
	{
		ulADCData=0;
		NVIC_EnableIRQ(EINT3_IRQn);
    LCD_DisplayStr(0,0,LEDBuffer);
		

	  sprintf (GcRcvBuf ,"VINO=%4dmV\r\n",SETTEMP);//½«Êý¾Ý·¢ËÍµ½´¿Ú½øÐÐÏÔÊ¾
		UART_SendStr(GcRcvBuf);//½«Êý¾Ý·¢ËÍµ½´¿ÚÏÔÊ¾
	}
}