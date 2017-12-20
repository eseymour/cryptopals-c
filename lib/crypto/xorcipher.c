#include "cipher.h"

void fixedXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
) {
  for (size_t i = 0; i < messageSize; ++i) {
    ciphertext[i] = message[i] ^ key[i];
  }
}
