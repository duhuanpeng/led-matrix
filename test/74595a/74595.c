#include "74595.h"

void write27b_74595(__far char *p) __naked
{
	p;
__asm

	push ACC
	mov A, r7
	push ACC
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

	pop ACC
	mov r7, A
	pop ACC
	ret
__endasm;

}

#if 1
void main(void)
{
	__far char buf[28*8];
	unsigned char i;

__init:
	for(i=0;i<sizeof(buf);i++){
		buf[i] = 0xff>>(i%8);
	}
	
init:
	buf[28*0] = ~(0x01<<0);
	buf[28*1] = ~(0x01<<1);
	buf[28*2] = ~(0x01<<2);
	buf[28*3] = ~(0x01<<3);
	buf[28*4] = ~(0x01<<4);
	buf[28*5] = ~(0x01<<5);
	buf[28*6] = ~(0x01<<6);
	buf[28*7] = ~(0x01<<7);


	for(i=0;;i++){
		write27b_74595(&buf[i*28]);
		i%=8;
		if(P1_5);else break;
	}

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
#endif

