#include "LPC11xx.h"                    // Device header
uint8_t SETTEMP;

void SEGinit()

{
	LPC_GPIO2->DIR|=0xFFF;
}

void KEYinit()

{

	LPC_GPIO3->DIR &=~(1<<0);
	LPC_GPIO3->DIR &=~(1<<1);

}

void BreakInit()

{
  LPC_GPIO3->IE|=(1<<0);

	LPC_GPIO3->IS&=~(1<<0);

	LPC_GPIO3->IEV&=~(1<<0);
	
	LPC_GPIO3->IE|=(1<<1);

	LPC_GPIO3->IS&=~(1<<1);

	LPC_GPIO3->IEV&=~(1<<1);
}

void PIOINT3_IRQHandler(void)
{
	if((LPC_GPIO3->MIS &(1<<0))==(1<<0))
	{
		SETTEMP=SETTEMP+1;
		LPC_GPIO3->IC |=(1<<0);
	}
	if((LPC_GPIO3->MIS &(1<<0))==(1<<0))
	{
		SETTEMP=SETTEMP-1;
		LPC_GPIO3->IC |=(1<<1);
	}
}
