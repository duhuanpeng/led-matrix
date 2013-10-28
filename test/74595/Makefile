CC := sdcc



test: m24x72.c 74595.o
	$(CC) $< 74595.rel
	


74595.o: 74595.c
	$(CC) $< -c


clean:
	rm -f *.asm *.lst *.o *.sym *.lnk *.rel *.map *.rst *.ihx *.mem *.hex

