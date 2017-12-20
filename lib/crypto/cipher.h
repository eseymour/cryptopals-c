#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>
#include <stdint.h>

void fixedXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
);

#endif // CRYPTO_H
