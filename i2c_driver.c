#include"header.h"
void i2c_init(void)
{
PINSEL0|=0X50;
I2SCLH=I2SCLL=75;
I2CONSET=(1<<6);
}
#define SI ((I2CONSET>>3)&1)
void i2c_byte_write_frame(unsigned char sa,unsigned char mr,unsigned char data)
{
I2CONSET=(1<<5);
I2CONCLR=(1<<3);
while(SI==0);
I2CONCLR=(1<<5);
I2DAT=sa;
I2CONCLR=(1<<3);
while(SI==0);
I2DAT=mr;
I2CONCLR=(1<<3);
while(SI==0);
I2DAT=data;
I2CONCLR=(1<<3);
while(SI==0);

I2CONSET=(1<<4);
I2CONCLR=(1<<3);
}

unsigned char i2c_byte_read_frame(unsigned char sa,unsigned char mr)
{
unsigned char temp=0;
I2CONSET=(1<<5);
I2CONCLR=(1<<3);
while(SI==0);
I2CONCLR=(1<<5);
I2DAT=sa;
I2CONCLR=(1<<3);
while(SI==0);
I2DAT=mr;
I2CONCLR=(1<<3);								 
while(SI==0);
I2CONSET=(1<<5);
I2CONCLR=(1<<3);
while(SI==0);
I2CONCLR=(1<<5);
I2DAT=sa|1;
I2CONCLR=(1<<3);
while(SI==0);
I2CONCLR=(1<<3);
while(SI==0);
temp=I2DAT;
I2CONSET=(1<<4);
I2CONCLR=(1<<3);
return temp;
}
