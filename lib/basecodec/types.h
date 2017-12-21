#ifndef BASECODEC_TYPES_H
#define BASECODEC_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
  size_t length;
  uint8_t bytes[];
} ByteString;

#endif // BASECODEC_TYPES_H
