#include "basecodec.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const char *base64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char * encodeBase64(ByteString *rawBytes) {
  size_t stringLen = (rawBytes->length / 3) * 4;

  char *encodedString = (char *) malloc(stringLen + 1);
  encodedString[stringLen] = '\0';

  for (size_t i = 0; i < rawBytes->length / 3; i++) {
    uint8_t curIndex = rawBytes->bytes[i*3] >> 2;
    encodedString[i*4] = base64chars[curIndex];

    curIndex = (rawBytes->bytes[i*3] << 4) & 0x30;
    curIndex |= (rawBytes->bytes[i*3 + 1] >> 4) & 0x0f;
    encodedString[i*4 + 1] = base64chars[curIndex];

    curIndex = (rawBytes->bytes[i*3 + 1] << 2) & 0x3c;
    curIndex |= (rawBytes->bytes[i*3 + 2] >> 6) & 0x03;
    encodedString[i*4 + 2] = base64chars[curIndex];

    curIndex = rawBytes->bytes[i*3 + 2] & 0x3f;
    encodedString[i*4 + 3] = base64chars[curIndex];
  }

  return encodedString;
}
