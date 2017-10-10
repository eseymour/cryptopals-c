SHELL = bash
CFLAGS = -O2 -g -std=c99 -Wall -Wextra -Werror -pedantic

.PHONY: all
all: fixedxor

fixedxor: fixedxor.o

fixedxor.o: fixedxor.c


.PHONY: clean
clean:
	rm -f fixedxor fixedxor.exe *.o
