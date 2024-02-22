#include"header.h"
main()
{
int i;
char ch;
char ptr[1000];
setBaudRate(9600);
i2c_init();
uart0_rx_string(ptr,1000);
for(i=0;i<1000;i++)
{
i2c_byte_write_frame(0xA0,0X00+i,ptr[i]);
delay_ms(10);
ch=i2c_byte_read_frame(0xA0,0X00+i);
uart0_tx(ch);
}
}
