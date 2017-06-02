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
			LPC_ADC ->CR |=(1<<24);//立即转换
			while((LPC_ADC->DR[0]&0X80000000)==0);//读取DR0的Done
			ulADCBuf=LPC_ADC ->DR[0];//读取结果寄存器
			ulADCBuf=(ulADCBuf>>6)&0x3ff;//数据 从第六位开始存储，占据10位
			ulADCData+=ulADCBuf ;//数据累加
			
		}
		ulADCData=ulADCData/10;//采样10次进行滤波
		ulADCData=(ulADCData*3300)/1024;//数字量转换成模拟量
//		sprintf (GcRcvBuf ,"VINO=%4dmV\r\n",ulADCData);//将数据发送到纯诮邢允�
//		UART_SendStr(GcRcvBuf );//将数据发送到纯谙允�
	}
}