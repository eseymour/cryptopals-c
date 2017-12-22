#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <analysis/frequency.h>
#include <basecodec/hexcodec.h>
#include <crypto/xorcrypt.h>

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
  float bestScore = INFINITY;
  for (uint16_t key = 0; key <= 0xff; ++key) {
    singleByteXorcrypt(ciphertext->bytes, key, (uint8_t *) message, ciphertext->length);
    message[ciphertext->length] = '\0';

    size_t actualDist[26];
    size_t count = calculateLetterFreqs(message, actualDist);

    // If letters found, we can skip this key.
    if (count > 0) {
      // See if this key is closer to the expected distribution.
      double score = chiSquared(englishLetterDist, actualDist, 26);
      score = (score * ciphertext->length) / count;
      if (score < bestScore) {
        bestKey = key;
        bestScore = score;
      }
    }
  }

  // Decode the best key
  singleByteXorcrypt(ciphertext->bytes, bestKey, (uint8_t *) message, ciphertext->length);
  message[ciphertext->length] = '\0';

  // Print out the fruits of our labor
  printf("found message \"%s\" using key 0x%2x\n", message, bestKey);

  free(ciphertext);
  free(message);

  return EXIT_SUCCESS;
}
