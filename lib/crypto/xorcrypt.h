#ifndef CRYPTO_CIPHER_H
#define CRYPTO_CIPHER_H

#include <stddef.h>
#include <stdint.h>

void xorcrypt(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize,
  size_t keySize
);

void fixedXorcrypt(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
);

void singleByteXorcrypt(
  uint8_t *message,
  uint8_t key,
  uint8_t *ciphertext,
  size_t messageSize
);

#endif // CRYPTO_CIPHER_H
