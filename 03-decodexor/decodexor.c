#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s hex_ciphertext\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
