#ifndef __74595_H__
#define __74595_H__

#include <8052.h>

/* define your hardward configure here */
#define CLR0	0
#define OE	0
#define RCK	P0.0
#define SCK	P0.4
#define SDI	P0.7

#define LED	P1.3

#define KEY1	P1.7
#define KEY2	P1.6
#define KEY3	P1.5
#define KEY4	P1.4



#define __set_iobit(pin)  __asm setb pin __endasm
#define __clr_iobit(pin)  __asm clr pin __endasm

void write27b_74595(__far char *p) __naked;

#endif

