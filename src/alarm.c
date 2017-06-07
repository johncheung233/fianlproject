#include "LPC11xx.h"                    // Device header
#include <stdio.h>
#include <string.h>
uint8_t  table[9]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0x0ff};
void Delay(uint32_t ulTime)
{
	uint32_t i;
	i=0;
		while(ulTime--)
	{
		for(i=0;i<5000;i++);
	}
}

void alarm()
{
	int a=0;
	while(1)
	{
		LPC_GPIO2->DATA = table[a];
		a++;
	  Delay(200);
	}
	
}
	