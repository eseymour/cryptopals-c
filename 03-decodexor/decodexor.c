#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <analysis/frequency.h>
#include <basecodec/hexcodec.h>
#include <crypto/cipher.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s hex_ciphertext\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  ByteString *ciphertext = decodeHex(argv[1]);
  // Used to store messages when decoding
  char *message = (char *) malloc(ciphertext->length + 1);

  // Try all possible 1 byte keys. Smallest chi-squared is likely the key.
  uint8_t bestKey = 0;
  float bestChi2 = INFINITY;
  for (uint16_t key = 0; key <= 0xff; ++key) {
    singleByteXorCipher(ciphertext->bytes, key, (uint8_t *) message, ciphertext->length);
    message[ciphertext->length] = '\0';

    double actualDist[26];
    size_t count = calculateLetterDist(message, actualDist);

    // If letters found, we can skip this key.
    if (count > 0) {
      // See if this key is closer to the expected distribution.
      double chi2 = chiSquared(englishLetterDist, actualDist, 26);
      if (chi2 < bestChi2) {
        bestKey = key;
        bestChi2 = chi2;
      }
    }
  }

  // Decode the best key
  singleByteXorCipher(ciphertext->bytes, bestKey, (uint8_t *) message, ciphertext->length);
  message[ciphertext->length] = '\0';

  // Print out the fruits of our labor
  printf("found message \"%s\" using key 0x%2x\n", message, bestKey);

  free(ciphertext);
  free(message);

  return EXIT_SUCCESS;
}
