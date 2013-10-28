#ifndef __74595_H__
#define __74595_H__

#include <8052.h>

/* define your hardward configure here */
#define CLR0	0
#define OE	0
#define RCK	P1.1
#define SCK	P2.2
#define SDI	P3.3


#define __set_bit(pin)  __asm setb pin __endasm
#define __clr_bit(pin)  __asm clr pin __endasm

#define flush_74595(pin)	__asm \
				setb RCK \
				clr RCK \
				__endasm

extern void writeb_74595(char ch) __naked;

#endif

