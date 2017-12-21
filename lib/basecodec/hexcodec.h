#ifndef BASECODEC_HEXCODEC_H
#define BASECODEC_HEXCODEC_H

#include "types.h"

ByteString * decodeHex(char *encodedString);
char * encodeHex(ByteString *rawBytes);

#endif // BASECODEC_HEXCODEC_H
