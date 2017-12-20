#ifndef BASECODEC_H
#define BASECODEC_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
  size_t length;
  uint8_t bytes[];
} ByteString;

ByteString * decodeBase64(char *encodedString);
ByteString * decodeHex(char *encodedString);
char * encodeBase64(ByteString *rawBytes);
char * encodeHex(ByteString *rawBytes);

#endif // ENCODING_H
