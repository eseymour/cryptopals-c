#ifndef BASECODEC_BASE64CODEC_H
#define BASECODEC_BASE64CODEC_H

#include "types.h"

ByteString * decodeBase64(char *encodedString);
char * encodeBase64(ByteString *rawBytes);

#endif // BASECODEC_BASE64CODEC_H
