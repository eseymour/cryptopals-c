#ifndef ANALYSIS_FREQUENCY_H
#define ANALYSIS_FREQUENCY_H

#include <stddef.h>

extern const double englishLetterDist[26];

size_t calculateLetterDist(const char *str, double dist[static 26]);
double chiSquared(const double *expected, const double *actual, size_t distSize);

#endif // ANALYSIS_FREQUENCY_H
