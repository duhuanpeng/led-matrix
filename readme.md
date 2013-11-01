### overview
![top](photo/ledm-top.jpg)
![bottom](photo/ledm-bottom.jpg)
![bare pcbs](photo/ledm-top.jpg)
![pcb top](photo/ledm-pcb-top.jpg)
![pcb bottom](photo/ledm-pcb-bottom.jpg)

### hardware
here is the [pcb](/hardware/led-matirx-pcb.zip) files in protel99se format.

### software
software was lost, but here is a simple example to driver the matrix.

```
#include <reg52.h>

#define BIT(c, n)	 (c & (1<<n))

sbit SDI = P0^7;
sbit SCK = P0^4;
sbit RCK = P0^0;

void write27b_74595(char xdata *p)
{
	char i=28;
	do{
		char c;
		c = *p++;
		SDI = BIT(c, 0);
		SCK = 1;
		SCK = 0;

		SDI = BIT(c, 1);
		SCK = 1;
		SCK = 0;

		SDI = BIT(c, 2);
		SCK = 1;
		SCK = 0;

		SDI = BIT(c, 3);
		SCK = 1;
		SCK = 0;

		SDI = BIT(c, 4);
		SCK = 1;
		SCK = 0;

		SDI = BIT(c, 5);
		SCK = 1;
		SCK = 0;
		
		SDI = BIT(c, 6);
		SCK = 1;
		SCK = 0;
		
		SDI = BIT(c, 7);
		SCK = 1;
		SCK = 0;
	}while(--i);
		RCK = 1;
		RCK = 0;
}

void main(void)
{
	xdata char buf[28*8]= 
"\xfe ABCDEFGHIJKLMNOPQRSTUVWXY\0"
"\xfd 11111111111111111111111111"
"\xfb QWERTYUIOPASDFGHJKLZXCVBNM"
"\xf7 22222222222222222222222222"
"\xef 33333333333333333333333333"
"\xdf 44444444444444444444444444"
"\xbf 55555555555555555555555555"
"\x7f 66666666666666666666666666";

/* put bitmap into buf */
	
	
	SDI = 1;
	SCK = 0;
	RCK = 0;
	
	buf[28*0] = ~(0x01<<0);
	buf[28*1] = ~(0x01<<1);
	buf[28*2] = ~(0x01<<2);
	buf[28*3] = ~(0x01<<3);
	buf[28*4] = ~(0x01<<4);
	buf[28*5] = ~(0x01<<5);
	buf[28*6] = ~(0x01<<6);
	buf[28*7] = ~(0x01<<7);


	while(1){ 
		write27b_74595(&buf[0*28]);
		write27b_74595(&buf[1*28]);
		write27b_74595(&buf[2*28]);
		write27b_74595(&buf[3*28]);
		write27b_74595(&buf[4*28]);
		write27b_74595(&buf[5*28]);
		write27b_74595(&buf[6*28]);
		write27b_74595(&buf[7*28]);
	}
}

```
example writen in ASM
```
SDI BIT P0.7
SCK BIT P0.4
RCK BIT P0.0

START:

	mov A, #0x7f
	mov dptr, #(28*0)
	movx @dptr, A
	
	rr A
	mov dptr, #(28*1)
	movx @dptr, A
	
	rr A
	mov dptr, #(28*2)
	movx @dptr, A

	rr A
	mov dptr, #(28*3)
	movx @dptr, A

	rr A
	mov dptr, #(28*4)
	movx @dptr, A

	rr A
	mov dptr, #(28*5)
	movx @dptr, A

	rr A
	mov dptr, #(28*6)
	movx @dptr, A

	rr A
	mov dptr, #(28*7)
	movx @dptr, A

; put your bitmap into xdata


display:
	mov dptr, #0
	lcall write27
	lcall write27
	lcall write27
	lcall write27
	lcall write27
	lcall write27
	lcall write27
	lcall write27
	sjmp display


write27: ;write select and 27 bytes.
	mov r7, #28
L1:
	movx A, @dptr
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK
	rrc A
	mov SDI, C
	setb SCK
	clr SCK

	inc dptr

	djnz r7, L1


	setb RCK
	clr RCK

	ret
	end

```
