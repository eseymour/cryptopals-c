#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <basecodec/basecodec.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "usage: %s hex_string\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  ByteString *rawBytes = decodeHex(argv[1]);
  char *base64 = encodeBase64(rawBytes);

  printf("%s\n", base64);

  free(rawBytes);
  free(base64);

  return EXIT_SUCCESS;
}
