/*
LE P3.0
DATA P3.1
CLK P3.2
author :fmehder
*/

#include <msp430x16x.h>
#include "delay.h"
#include "mb1504.h"
void InitSys();
void main()
{
  WDTCTL = WDTPW + WDTHOLD;
  InitSys();                                //set system clock as 8MHz
  P3DIR=0XFF;
  SendReferF( );           		// MB1504   send control word
  delay_ms(1);     
  
  FrequenceToSend(8500);  	           //  change frequency here 
                                      // 10000 as 100M
  while (1);															

}



void InitSys()
{
   unsigned int i;
   BCSCTL1 &=~XT2OFF;       //��XT2���پ���
   do
   {
      IFG1 &= ~OFIFG;			// �������ʧЧ��־
    for (i = 0xFF; i > 0; i--);	   // ��ʱ���ȴ�XT2����
   }
   while ((IFG1 & OFIFG) != 0);		// �ж�XT2�Ƿ�����		
   BCSCTL2 =SELS+DIVS_0;            //SMCLKʱ��ΪXT2=8MHz   ����Ƶ
							
}