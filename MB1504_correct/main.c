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
   BCSCTL1 &=~XT2OFF;       //打开XT2高速晶振
   do
   {
      IFG1 &= ~OFIFG;			// 清除振荡器失效标志
    for (i = 0xFF; i > 0; i--);	   // 延时，等待XT2起振
   }
   while ((IFG1 & OFIFG) != 0);		// 判断XT2是否起振		
   BCSCTL2 =SELS+DIVS_0;            //SMCLK时钟为XT2=8MHz   不分频
							
}