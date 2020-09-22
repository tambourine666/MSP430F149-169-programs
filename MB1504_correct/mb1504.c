#include <MSP430X16X.H>
#include "mb1504.h"
#include "delay.h"

//--------------------------------------------------------------
void Send16Bit(unsigned int SendData)												//????  ??16???
{
	uchar i;
	uint SendMiddle;
	SendMiddle=SendData;
	LE_L;
	CLK_L;
	for(i=0;i<16;i++)																	//?????
	{
		if((SendMiddle & 0x8000)==0x8000)
		{
			DATA_H;
		}
		else
		{
			DATA_L;
		}
		delay_us (2);
		CLK_H;																					//????
		delay_us (2);
		CLK_L;
		SendMiddle= SendMiddle<<1;
	}
	LE_H;
	delay_us (2);
	LE_L;
}

//-----------------------------------------------------------------
//Send11Bit(uint SendData) 
//-----------------------------------------------------------------
//
// ????: ???11?????
// ????: SendData
// ????: ? 
// ????: ?
// ????: 
// ????: 
//-----------------------------------------------------------------
void Send11Bit(unsigned int SendData)   										
{   
  uchar i;   
  LE_L;       
	CLK_L;   
  for( i = 0; i < 11; i ++ )   
  {   
		if((SendData & 0x8000)==0x8000)
		{
			DATA_H;
		}
		else
		{
			DATA_L;
		}		
    delay_us (2);      
		CLK_H;   
    delay_us (2);        
		CLK_L;   
    SendData = SendData << 1;   
  }   
}   

//-----------------------------------------------------------------
//Send8Bit( uchar SendData )   
//-----------------------------------------------------------------
//
// ????: ???8?????
// ????: SendData
// ????: ? 
// ????: ?
// ????: 
// ????: 
//-----------------------------------------------------------------	
void Send8Bit( unsigned char SendData )   													//???8???
{   
  uchar i;    
  for( i = 0; i < 8; i ++ )   
  {   
		if((SendData & 0x80)==0x80)
		{
			DATA_H;
		}
		else
		{
			DATA_L;
		}				
    delay_us (2);        
		CLK_H;   
    delay_us (2);        
		CLK_L;   
    SendData = SendData << 1;   
   }   
		LE_H;        
  	delay_us (2);        
	  LE_L;   
}   

//-----------------------------------------------------------------
//SendReferF( void ) 
//-----------------------------------------------------------------
//
// ????: ????????
// ????: ?
// ????: ? 
// ????: ?
// ????: 
// ????: 
//-----------------------------------------------------------------
void SendReferF( void )   
{  		   
  Send16Bit( 0x8641 );   // control word   
//Fvco = (P * N + A)*Fosc / R	   , R = Fosc / Fr
  
 //针对晶体 采用 8M,  SW = 1, C = 1
  //8M / 10k = 800 = 0x0320 ,(0x0320 << 1) | 0x8001 = 0x8641   
}   
   
void FrequenceToSend( uint FrequenceD )   
{   
  uchar AD = 0;       
  uint  ND = 0;      
	uint MiddleF = 2000;   
   
          MiddleF = FrequenceD;   								//????P?32
          ND = ( uint  ) ( MiddleF / 32 );    	 //???=32*ND+AD;		
          AD = ( uchar ) ( MiddleF % 32 );   
          ND = ND << 5;               
	AD = AD << 1;       										//???????,
	AD = AD & 0xfe;													//??? ??;
          Send11Bit( ND );        								
	Send8Bit( AD );   
}   


//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
