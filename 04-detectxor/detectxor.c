#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s file\n", strrchr(argv[0], '/') + 1);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
