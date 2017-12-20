#include "cipher.h"

void repeatingKeyXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *cipherText,
  size_t messageSize,
  size_t keySize
) {
  for (size_t i = 0; i < messageSize; i++) {
    cipherText[i] = message[i] ^ key[i % keySize];
  }
}

void fixedXorCipher(
  uint8_t *message,
  uint8_t *key,
  uint8_t *ciphertext,
  size_t messageSize
) {
  repeatingKeyXorCipher(message, key, ciphertext, messageSize, messageSize);
}

void singleByteXorCipher(
  uint8_t *message,
  uint8_t key,
  uint8_t *ciphertext,
  size_t messageSize
) {
  repeatingKeyXorCipher(message, &key, ciphertext, messageSize, 1);
}
