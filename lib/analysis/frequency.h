#ifndef ANALYSIS_FREQUENCY_H
#define ANALYSIS_FREQUENCY_H

#include <stddef.h>

extern const double englishLetterDist[26];

size_t calculateLetterFreqs(const char *str, size_t freqs[static 26]);
double chiSquared(const double *expected, const size_t *actual, size_t distSize);

#endif // ANALYSIS_FREQUENCY_H
