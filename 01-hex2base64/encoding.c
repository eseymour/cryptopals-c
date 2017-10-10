#include "encoding.h"

#include <stdio.h>
#include <stdlib.h>

ByteString * decodeHex(char *encodedString) {
  (void)encodedString;
  fprintf(stderr, "%s not implemented yet.", __func__);

  exit(EXIT_FAILURE);
}

char * encodeBase64(ByteString *rawBytes) {
  (void)rawBytes;
  fprintf(stderr, "%s not implemented yet.", __func__);

  exit(EXIT_FAILURE);
}
