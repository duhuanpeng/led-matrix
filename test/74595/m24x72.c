#include "74595.h"

/*

buf
 [select] dot ... [  ]
 [0x01]  [ 1] ... [27]
 [0x02]  [28] ... []
       ......
 [0x80]  [196] ... []
*/

__far static char m24x72_buf[(27+1)*8];


void m24x72_init(void)
{
	unsigned char i;
	unsigned char j = 0;
/* put your bitmap into buf. */
	for(i=0;i<sizeof(m24x72_buf);i++){
		m24x72_buf[i] = ++j;
	}
/* end of bitmap */

/* swap lines by changing buf[28*x]. */	
	m24x72_buf[28*0] = ~(0x01<<0);
	m24x72_buf[28*1] = ~(0x01<<1);
	m24x72_buf[28*2] = ~(0x01<<2);
	m24x72_buf[28*3] = ~(0x01<<3);
	m24x72_buf[28*4] = ~(0x01<<4);
	m24x72_buf[28*5] = ~(0x01<<5);
	m24x72_buf[28*6] = ~(0x01<<6);
	m24x72_buf[28*7] = ~(0x01<<7);

	__set_bit(SDI);	
	__clr_bit(SCK);
	__clr_bit(RCK);
}

void m72x24_write27b(char p[], char select)
{
	char i;
	select;

	for(i=0;i<28;i++){
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
	unsigned long n=900000;
	__clr_bit(SDI);
	while(P1_7 && n--);
	
	m24x72_init();
	for(;;)
	m72x24_driver(); 
}

