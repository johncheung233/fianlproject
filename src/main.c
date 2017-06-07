#include "LPC11xx.h"                    // Device header
#include "ADC.h"
#include "BREAK.h"
#include "lcd.h"
#include "UART.h"
#include "measure.h"
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
	extern char mea[20];
	extern 	uint16_t T;
	char GcRcvBuf[20];
	char first[20];
	char lcdfirst[]="welcome";
	BreakInit();
	KEYinit();
	SEGinit();
	InitLCD();
	LCD_IOInit();
	ADC_Init();
	UART_Init();

	
	while(1) 
	{
			
		sprintf (first,"%s",lcdfirst);
	  LCD_DisplayStr(5,0,first);
		NVIC_EnableIRQ(EINT3_IRQn);//中断判断按键
    LCD_DisplayStr(0,1,LEDBuffer);//显示设定报警的值
		 measure();
		LCD_DisplayStr(7,1,mea);
	  sprintf (GcRcvBuf ,"VINO=%4dmV\r\n",SETTEMP);//将数据传送到pc
		UART_SendStr(GcRcvBuf);//将数据传送到pc
	}
}