CFLAGS = -O2 -g -std=c99 -Wall -Wextra -Werror -pedantic

.PHONY: all
all: hex2base64

hex2base64: hex2base64.o

hex2base64.o: hex2base64.c

.PHONY: clean
clean:
	rm -f hex2base64 hex2base64.exe *.o
