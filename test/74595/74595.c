#include "74595.h"

void writeb_74595(char ch) __naked
{
	ch;
__asm
	push ACC
	mov A, dpl

	mov SDI, ACC.0
	setb SCK
	clr SCK

	mov SDI, ACC.1
	setb SCK
	clr SCK

	mov SDI, ACC.2
	setb SCK
	clr SCK

	mov SDI, ACC.3
	setb SCK
	clr SCK

	mov SDI, ACC.4
	setb SCK
	clr SCK

	mov SDI, ACC.5
	setb SCK
	clr SCK

	mov SDI, ACC.6
	setb SCK
	clr SCK

	mov SDI, ACC.7
	setb SCK
	clr SCK

	pop ACC
	ret
__endasm;
}

#if 0
void main(void)
{
	while(1){
		writeb_74595(0xaa);
		flush_74595();
		__set_bit(SDI);
		__clr_bit(SDI);
	}
		
}
#endif
