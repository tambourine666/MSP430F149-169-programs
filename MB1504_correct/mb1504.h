void GPIO_LED_Configuration(void);
void Send16Bit(unsigned int SendData);
void Send11Bit( unsigned int SendData ) ;  
void Send8Bit( unsigned char SendData ) ; 
void SendReferF( void )  ;
void FrequenceToSend( unsigned int FrequenceD ); 

#define  LE_H        P3OUT|=BIT0
#define  LE_L        P3OUT&=~BIT0

#define  DATA_H      P3OUT|=BIT1	          //       DATA  1.1
#define  DATA_L      P3OUT&=~BIT1        
                    
#define  CLK_H       P3OUT|=BIT2              // 	 CLK   1.2
#define  CLK_L       P3OUT&=~BIT2 

