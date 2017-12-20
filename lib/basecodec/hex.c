#include "basecodec.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define hex2nibble(x) (isdigit(x) ? x-'0' : isupper(x) ? x-'A'+10 : x-'a'+10)

ByteString * decodeHex(char *encodedString) {
  size_t numBytes = strlen(encodedString) / 2;

  ByteString *rawBytes = (ByteString *) malloc(sizeof(ByteString) + numBytes);
  rawBytes->length = numBytes;

  for (size_t i = 0; i < numBytes; ++i) {
    byte_t curByte = hex2nibble(encodedString[i*2]) << 4;
    curByte |= hex2nibble(encodedString[i*2 + 1]);

    rawBytes->bytes[i] = curByte;
  }

  return rawBytes;
}
