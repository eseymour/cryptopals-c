#ifndef BASECODEC_H
#define BASECODEC_H

#include <stddef.h>
#include <stdint.h>

typedef uint8_t byte_t;

typedef struct {
  size_t length;
  byte_t bytes[];
} ByteString;

ByteString * decodeHex(char *encodedString);
char * encodeBase64(ByteString *rawBytes);

#endif // ENCODING_H
