#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <basecodec/hexcodec.h>
#include <crypto/xorcrypt.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s key\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  char *key = argv[1];
  size_t keySize = strlen(key);
  ByteString *plaintext = malloc(sizeof(ByteString) + keySize);

  size_t bytesRead;
  while ((bytesRead = fread(plaintext->bytes, 1, keySize, stdin))) {
    plaintext->length = bytesRead;
    fixedXorcrypt(plaintext->bytes, (uint8_t *) key, plaintext->bytes, bytesRead);

    char *ciphertext = encodeHex(plaintext);
    printf("%s", ciphertext);
    free(ciphertext);
  }

  printf("\n");
  free(plaintext);

  return EXIT_SUCCESS;
}
