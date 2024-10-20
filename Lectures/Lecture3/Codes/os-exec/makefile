all: minimal static

minimal.o: minimal.c
	gcc -c -o $@ $<

minimal: minimal.o
	ld -o $@ $<

minimal-asm: minimal
	objdump -d $<

static: minimal.o
	gcc -static -o $@ $<

static-asm: static
	objdump -d $<

clean:
	-rm -f minimal.o minimal static

.PHONY: all minimal-asm static-asm clean
