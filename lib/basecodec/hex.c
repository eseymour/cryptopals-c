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
    uint8_t curByte = hex2nibble(encodedString[i*2]) << 4;
    curByte |= hex2nibble(encodedString[i*2 + 1]);

    rawBytes->bytes[i] = curByte;
  }

  return rawBytes;
}

const char *hexChars = "0123456789abcdef";

char * encodeHex(ByteString *rawBytes) {
  size_t stringLen = rawBytes->length * 2;
  char *encodedString = (char *) malloc(stringLen + 1);

  for (size_t i = 0; i < rawBytes->length; i++) {
    uint8_t nibble = rawBytes->bytes[i] >> 4;
    encodedString[i * 2] = hexChars[nibble];

    nibble = rawBytes->bytes[i] & 0xf;
    encodedString[i * 2 + 1] = hexChars[nibble];
  }

  return encodedString;
}
