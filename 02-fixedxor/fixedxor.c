#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <basecodec/hexcodec.h>
#include <crypto/cipher.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s hex_message hex_key\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  if (strlen(argv[1]) != strlen(argv[2])) {
    fprintf(stderr, "key and message lengths do not match\n");
    return EXIT_FAILURE;
  }

  ByteString *message = decodeHex(argv[1]);
  ByteString *key = decodeHex(argv[2]);

  fixedXorCipher(message->bytes, key->bytes, message->bytes, message->length);

  char *encodedMessage = encodeHex(message);
  printf("%s\n", encodedMessage);

  free(message);
  free(key);
  free(encodedMessage);

  return EXIT_SUCCESS;
}
