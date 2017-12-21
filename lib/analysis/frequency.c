#include "frequency.h"

#include <ctype.h>

size_t calculateLetterDist(const char *str, double dist[static 26]) {
  size_t letterFreqs[26] = {0};
  size_t count = 0;

  for (; *str != '\0'; ++str) {
    char c = *str;
    if (isalpha(c)) {
      ++count;
      ++letterFreqs[tolower(c) - 'a'];
    }
  }

  if (count != 0) {
    for (int i = 0; i < 26; ++i) {
      dist[i] = letterFreqs[i] / (double) count;
    }
  }

  return count;
}

double calculateChiSquared(const double *expected, const double *actual, size_t distSize) {
  double chiSquared = 0;

  for (size_t i = 0; i < distSize; i++) {
    double difference = actual[i] - expected[i];
    chiSquared += difference * difference / expected[i];
  }

  return chiSquared;
}
