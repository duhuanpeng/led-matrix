#include <stdio.h>
#include <8052.h>

void putchar (char c)
{
	P0 = c;
}

void main(void)
{
	printf("Hello\n");
}
