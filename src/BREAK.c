#include "LPC11xx.h"                    // Device header
#include <stdio.h>

uint8_t SETTEMP=29;
char LEDBuffer[20];
void SEGinit()

{
	LPC_GPIO2->DIR|=0xFFF;
}

void KEYinit()

{

	LPC_GPIO3->DIR &=~(1<<2);
	LPC_GPIO3->DIR &=~(1<<3);

}

void BreakInit()

{
  LPC_GPIO3->IE|=(1<<2);

	LPC_GPIO3->IS&=~(1<<2);

	LPC_GPIO3->IEV&=~(1<<2);
	
	LPC_GPIO3->IE|=(1<<3);

	LPC_GPIO3->IS&=~(1<<3);

	LPC_GPIO3->IEV&=~(1<<3);
}

 void PIOINT3_IRQHandler(void)
{
 
	if((LPC_GPIO3->MIS &(1<<2))==(1<<2))
	{
		SETTEMP++;
		LPC_GPIO3->IC |=(1<<2);
	}
	if((LPC_GPIO3->MIS &(1<<3))==(1<<3))
	{
		SETTEMP--;
		LPC_GPIO3->IC |=(1<<3);
	}
	sprintf ( LEDBuffer,"SET=%d",SETTEMP);
}

