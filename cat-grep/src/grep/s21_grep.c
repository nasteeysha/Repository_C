#include "s21_grep.h"

static const char *optstr = "ef:ivclnhsfo";

int ReadFlags(int argc, char **argv, flags *Flags) {
  int flag = 1;
  int res;
  int needOpt = 1;
  int optIn = 0;
  const struct option longOptions[] = {{NULL, 0, NULL, 0}};
  while ((res = getopt_long(argc, argv, optstr, longOptions, &optIn)) != -1) {
    Flags->e = 1;
    needOpt = 0;
    switch (res) {
      case 'i': {
        Flags->i = 1;
        break;
      };

      case 'e': {
        Flags->e = 1;
        Flags->f = 0;
        break;
      };

      case 'h': {
        Flags->h = 1;
        break;
      }

      case 'v': {
        Flags->v = 1;
        break;
      }

      case 'c': {
        Flags->c = 1;
        break;
      }

      case 'l': {
        Flags->l = 1;
        break;
      }

      case 'n': {
        Flags->n = 1;
        break;
      }

      case 'f': {
        Flags->e = 0;
        Flags->f = 1;
        break;
      }

      case 's': {
        Flags->s = 1;
        opterr = 0;
        break;
      }

      case 'o': {
        Flags->o = 1;
        break;
      }

      case '?': {
        flag = res;
        break;
      }
      default: {
        Flags->noOpt = 1;
        break;
      }
    }
  }

  // if(Flags->v && Flags->o) {
  //   Flags->v = 0;
  // }

  // if(Flags->v && Flags->c) {
  //   Flags->o = 0;
  // }

  if (needOpt == 1) {
    Flags->e = 1;
    Flags->noOpt = 1;
  }

  if (optind + 2 < argc) {
    Flags->notOneFile = 1;
  }
  return flag;
}

int ReadFile(flags Flags, char *pattern, char *file) {
  regex_t reegex;
  regcomp(&reegex, pattern, REG_EXTENDED);
  FILE *f;

  if ((f = fopen(file, "r")) != NULL) {
    char str[9999];
    int count = 0;
    int countString = 0;
    while ((fgets(str, 9999, f)) != NULL) {
      countString++;
      int resSearch;
      resSearch = regexec(&reegex, str, 0, NULL, 0);

      if (Flags.i) {
        regfree(&reegex);
        regcomp(&reegex, pattern, REG_ICASE);
        resSearch = regexec(&reegex, str, 0, NULL, 0);
      }

      if (Flags.v) {
        resSearch = !resSearch;
      }

      if (Flags.h) {
        Flags.notOneFile = 0;
      }

      if (resSearch == 0) {
        count++;
        if (str[strlen(str) - 1] != '\n') {
          int end = strlen(str);
          str[end] = '\n';
          str[end + 1] = '\0';
        }

        if (Flags.c != 1 && Flags.l != 1) {
          if (Flags.notOneFile && Flags.n) {
            printf("%s:%d:%s", file, countString, str);
          } else if (Flags.notOneFile && !Flags.n) {
            printf("%s:%s", file, str);
          } else if (!Flags.notOneFile && Flags.n) {
            printf("%d:%s", countString, str);
          } else {
            printf("%s", str);
          }
        }
      }
    }

    if (Flags.c && !Flags.l) {
      if (Flags.notOneFile) {
        printf("%s:%d\n", file, count);
      } else {
        printf("%d\n", count);
      }
    }

    if (Flags.c && Flags.l) {
      // if (count == 0) {
      //   count = 0;
      // } else {
      //   count = 1;
      // }
      if (count != 0) {
        count = 1;
      }
      if (Flags.notOneFile) {
        printf("%s:%d\n", file, count);
      } else {
        printf("%d\n", count);
      }
    }

    if (Flags.l && count != 0) {
      count = 1;
      printf("%s\n", file);
    }
    fclose(f);
  }

  regfree(&reegex);
  return 1;
}
