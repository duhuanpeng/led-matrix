#include "74595.h"

/*

buf
  dot ... [  ][select]
 [ 0] ... [27][  0x01]
 [29] ... [56][  0x02]
*/

__far static char m24x72_buf[(27+1)*8];


void m24x72_init(void)
{
	m24x72_buf[27*1] = 0x01<<0;
	m24x72_buf[27*2] = 0x01<<1;
	m24x72_buf[27*3] = 0x01<<2;
	m24x72_buf[27*4] = 0x01<<3;
	m24x72_buf[27*5] = 0x01<<4;
	m24x72_buf[27*6] = 0x01<<5;
	m24x72_buf[27*7] = 0x01<<6;
	m24x72_buf[27*8] = 0x01<<7;
}

void m72x24_write27b(char p[], char select)
{
	char i;
	select;

	for(i=0;i<=28;i++){
		writeb_74595(p[i]);
	}
	flush_74595(); 
}

void m72x24_driver(void)
{
	static char i = 0;
	m72x24_write27b(&m24x72_buf[i*28], 1);
	i += 1;
	i %= 8; 
	return;
}

void main(void)
{
	for(;;)
	m72x24_driver(); 
}

