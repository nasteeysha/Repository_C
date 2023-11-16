#include "s21_cat.h"
int main(int argc, char *argv[]) {
  flags Flags = {0};

  if (ReadFlags(argc, argv, &Flags) == 1) {
    while (optind < argc) {
      int res = ReadFile(&Flags, argv);
      if (res == -1) {
        fprintf(stderr, "cat: %s: No such file or directory", argv[optind]);
      }

      if (res == -2) {
        fprintf(stderr, "cat: %s: Is a directory", argv[optind]);
      }
      optind++;
    }
  }
}