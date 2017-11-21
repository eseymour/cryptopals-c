SHELL = bash
CFLAGS = -O2 -g -std=c99 -Wall -Wextra -Werror -pedantic

.PHONY: all
all: hex2base64

hex2base64: hex2base64.o encoding.o

hex2base64.o: hex2base64.c encoding.h
encoding.o: encoding.c encoding.h

.PHONY: check
check: hex2base64
	$(SHELL) hex2base64_test.sh

.PHONY: clean
clean:
	rm -rf hex2base64 hex2base64.exe hex2base64.dSYM *.o
