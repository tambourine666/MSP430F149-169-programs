#define CPU_F    ((double)1000000) 
#define delay_us(x)      __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x)      __delay_cycles((long)(CPU_F*(double)x/1000.0)) 
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long