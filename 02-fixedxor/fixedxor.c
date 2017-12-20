#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <basecodec/basecodec.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s hex_message hex_key\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  if (strlen(argv[1]) != strlen(argv[2])) {
    fprintf(stderr, "key and message lengths do not match\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
