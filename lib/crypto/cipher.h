#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>
#include <stdint.h>

void repeatingKeyXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *cipherText,
  size_t messageSize,
  size_t keySize
);

void fixedXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
);

void singleByteXorCipher(
  uint8_t *message,
  uint8_t key,
  uint8_t *ciphertext,
  size_t messageSize
);

#endif // CRYPTO_H
