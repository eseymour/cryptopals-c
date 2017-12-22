#include "frequency.h"

#include <ctype.h>

size_t calculateLetterFreqs(const char *str, size_t freqs[static 26]) {
  size_t count = 0;

  for (size_t i = 0; i < 26; ++i) {
    freqs[i] = 0;
  }

  for (; *str != '\0'; ++str) {
    char c = *str;
    if (isalpha(c)) {
      ++count;
      ++freqs[tolower(c) - 'a'];
    }
  }

  return count;
}

double chiSquared(const double *expected, const size_t *actual, size_t distSize) {
  double chi2 = 0;
  size_t count = 0;

  for (size_t i = 0; i < distSize; ++i) {
    count += actual[i];
  }

  for (size_t i = 0; i < distSize; ++i) {
    double difference = actual[i] - count * expected[i];
    chi2 += difference * difference / (count * expected[i]);
  }

  return chi2;
}
