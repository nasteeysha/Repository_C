#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flags Flags = {0};
  ReadFlags(argc, argv, &Flags);
  char *pattern = argv[optind];
  while (optind < argc) {
    ReadFile(Flags, pattern, argv[optind]);
    optind++;
  }
}