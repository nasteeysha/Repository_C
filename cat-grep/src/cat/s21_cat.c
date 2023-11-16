#include "s21_cat.h"
int ReadFlags(int argc, char *argv[], flags *Flags) {
  int flag = 1;
  int r = 0;
  int optionIndex = 0;
  const struct option longOptions[] = {{"number", 0, NULL, 'n'},
                                       {"number-nonblank", 0, NULL, 'b'},
                                       {"squeeze-blank", 0, NULL, 's'},
                                       {NULL, 0, NULL, 0}};

  while ((r = getopt_long(argc, argv, "bevEnstT", longOptions, &optionIndex)) !=
         -1) {
    switch (r) {
      case 'v': {
        Flags->v = 1;
        break;
      };

      case 'b': {
        Flags->b = 1;
        break;
      };

      case 'e': {
        Flags->e = 1;
        Flags->v = 1;
        break;
      };

      case 'n': {
        Flags->n = 1;
        break;
      };

      case 's': {
        Flags->s = 1;
        break;
      };

      case 't': {
        Flags->t = 1;
        Flags->v = 1;
        break;
      }

      case 'E': {
        Flags->E = 1;
        Flags->v = 0;
        break;
      };

      case 'T': {
        Flags->T = 1;
        Flags->v = 0;
        break;
      };

      case '?':
      default: {
        flag = r;
        break;
      };
    }
  }
  return flag;
}

int ReadFile(flags *Flags, char **argv) {
  int flag = 1;
  FILE *f;
  // char ch = '\n';
  // char ch2;
  // int strCount = 0;
  // int counter = 1;
  if ((f = fopen(argv[optind], "r")) != NULL) {
    if (is_regular_file(argv[optind])) {
      char ch = '\n';
      char ch2;
      int strCount = 0;
      int counter = 1;
      while ((ch2 = fgetc(f)) != EOF) {
        if (Flags->s && ch == '\n' && ch2 == '\n') {
          strCount++;
          if (strCount > 1) {
            continue;
          }
        }

        if ((Flags->n && ch == '\n' && !Flags->b) ||
            ((Flags->b) && ch == '\n' && ch2 != '\n')) {
          printf("%6d\t", counter++);
        }

        if (Flags->e == 1 && ch2 == '\n') {
          printf("$");
        }

        if (Flags->t && ch2 == '\t') {
          printf("^");
          ch2 = 'I';
        }

        if (Flags->v && !(ch2 >= 32 && ch2 < 127) && ch2 != '\n' &&
            ch2 != '\t') {
          if (ch2 == 127) {
            printf("^");
            ch2 -= 64;
          } else if (ch2 < 32 && ch2 >= 0) {
            printf("^");
            ch2 += 64;
          }
        }

        if (ch == '\n' && ch2 != '\n') {
          strCount = 0;
        }
        ch = ch2;
        printf("%c", ch2);
      }
    } else {
      flag = -2;
    }
    fclose(f);
  } else {
    flag = -1;
  }
  return flag;
}

int is_regular_file(char *filename) {
  struct stat file_stat;
  stat(filename, &file_stat);
  return S_ISREG(file_stat.st_mode);
}