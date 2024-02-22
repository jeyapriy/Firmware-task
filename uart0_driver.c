#include"header.h"
void setBaudRate(unsigned int baudRate)
 {
  unsigned int divisor = 15000000 / (baudRate * 16); 
    PINSEL0|=0X5;
		U0LCR=0X83;
    U0DLL = divisor & 0xFF;
    U0DLM = (divisor >> 8) & 0xFF;
		U0LCR=0X03;
}


#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
  U0THR=data;
	while(THRE==0);
}

#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(char *ptr)
{
while(*ptr!=0)
{
U0THR=*ptr;
while(THRE==0);
ptr++;
}
}

void uart0_rx_string(char *ptr,int max_bytes)
{
int i;
for(i=0;i<max_bytes;i++)
{
while(RDR==0);
ptr[i]=U0RBR;
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';
}
