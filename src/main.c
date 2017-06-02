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
			LPC_ADC ->CR |=(1<<24);//����ת��
			while((LPC_ADC->DR[0]&0X80000000)==0);//��ȡDR0��Done
			ulADCBuf=LPC_ADC ->DR[0];//��ȡ����Ĵ���
			ulADCBuf=(ulADCBuf>>6)&0x3ff;//���� �ӵ���λ��ʼ�洢��ռ��10λ
			ulADCData+=ulADCBuf ;//�����ۼ�
			
		}
		ulADCData=ulADCData/10;//����10�ν����˲�
		ulADCData=(ulADCData*3300)/1024;//������ת����ģ����
//		sprintf (GcRcvBuf ,"VINO=%4dmV\r\n",ulADCData);//�����ݷ��͵���ڽ�����ʾ
//		UART_SendStr(GcRcvBuf );//�����ݷ��͵������ʾ
	}
}