#include "74595.h"

void writeb_74595(char ch) __naked
{
	ch;
__asm
	push ACC
	mov A, dpl
#if 0
	rlc A
	mov SDI, C
	setb SCK
	clr SCK

	rlc A
	mov SDI, C
	setb SCK
	clr SCK
	
	rlc A
	mov SDI, C
	setb SCK
	clr SCK

	rlc A
	mov SDI, C
	setb SCK
	clr SCK
	
	rlc A
	mov SDI, C
	setb SCK
	clr SCK
	
	rlc A
	mov SDI, C
	setb SCK
	clr SCK
	
	rlc A
	mov SDI, C
	setb SCK
	clr SCK
	
	rlc A
	mov SDI, C
	setb SCK
	clr SCK
#else
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

#endif
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
