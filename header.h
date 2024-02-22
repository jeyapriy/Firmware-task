#include <LPC21xx.H>

//delay

extern void delay_ms(unsigned int ms);
extern void delay_s(unsigned int s);


//uart

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_rx_string(char *p,int max);
extern void uart0_tx_integer(unsigned int temp);

 //lcd

extern void lcd_init(void);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);

//i2c
extern void i2c_init(void);
extern void i2c_byte_write_frame(unsigned char sa,unsigned char mr,unsigned char data);
extern unsigned char i2c_byte_read_frame(unsigned char sa,unsigned char mr);

		

