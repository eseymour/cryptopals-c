#include "xorcrypt.h"

void xorcrypt(
  uint8_t *plaintext,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize,
  size_t keySize
) {
  for (size_t i = 0; i < messageSize; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keySize];
  }
}

void fixedXorcrypt(
  uint8_t *plaintext,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
) {
  xorcrypt(plaintext, key, ciphertext, messageSize, messageSize);
}

void singleByteXorcrypt(
  uint8_t *plaintext,
  uint8_t key,
  uint8_t *ciphertext,
  size_t messageSize
) {
  xorcrypt(plaintext, &key, ciphertext, messageSize, 1);
}
