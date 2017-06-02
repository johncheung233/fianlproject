#include "LPC11xx.h"                    // Device header
#include "ADC.h"
#include "BREAK.H"
#define UART_BPS 115200
 uint8_t SETTEMP=30;

int main()
{
uint32_t i;
uint32_t ulADCData;
uint32_t ulADCBuf;
	void BreakInit();
	void KEYinit();
	void SEGinit();

	while(1)
	{
		NVIC_EnableIRQ(EINT3_IRQn);
		ulADCData=0;
		for(i=0;i<10;i++)
		{
			LPC_ADC ->CR |=(1<<24);//Á¢¼´×ª»»
			while((LPC_ADC->DR[0]&0X80000000)==0);//¶ÁÈ¡DR0µÄDone
			ulADCBuf=LPC_ADC ->DR[0];//¶ÁÈ¡½á¹û¼Ä´æÆ÷
			ulADCBuf=(ulADCBuf>>6)&0x3ff;//Êý¾Ý ´ÓµÚÁùÎ»¿ªÊ¼´æ´¢£¬Õ¼¾Ý10Î»
			ulADCData+=ulADCBuf ;//Êý¾ÝÀÛ¼Ó
			
		}
		ulADCData=ulADCData/10;//²ÉÑù10´Î½øÐÐÂË²¨
		ulADCData=(ulADCData*3300)/1024;//Êý×ÖÁ¿×ª»»³ÉÄ£ÄâÁ¿
//		sprintf (GcRcvBuf ,"VINO=%4dmV\r\n",ulADCData);//½«Êý¾Ý·¢ËÍµ½´¿Ú½øÐÐÏÔÊ¾
//		UART_SendStr(GcRcvBuf );//½«Êý¾Ý·¢ËÍµ½´¿ÚÏÔÊ¾
	}
}