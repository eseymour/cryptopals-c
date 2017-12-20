#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <basecodec/basecodec.h>

ByteString * fixedXorEncode(ByteString *rawMessage, ByteString *rawKey);

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s hex_message hex_key\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  if (strlen(argv[1]) != strlen(argv[2])) {
    fprintf(stderr, "key and message lengths do not match\n");
    return EXIT_FAILURE;
  }

  ByteString *rawMessage = decodeHex(argv[1]);
  ByteString *rawKey = decodeHex(argv[2]);
  ByteString *rawEncodedMessage = fixedXorEncode(rawMessage, rawKey);

  char *encodedMessage = encodeHex(rawEncodedMessage);
  printf("%s\n", encodedMessage);

  free(rawMessage);
  free(rawKey);
  free(rawEncodedMessage);
  free(encodedMessage);

  return EXIT_SUCCESS;
}

ByteString * fixedXorEncode(ByteString *rawMessage, ByteString *rawKey) {
  size_t messageLen = rawMessage->length;

  ByteString *encodedMessage = (ByteString *) malloc(sizeof(ByteString) + messageLen);
  encodedMessage->length = messageLen;

  for (size_t i = 0; i < messageLen; ++i) {
    encodedMessage->bytes[i] = rawMessage->bytes[i] ^ rawKey->bytes[i];
  }

  return encodedMessage;
}
