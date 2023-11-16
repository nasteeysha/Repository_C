#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>  //unistd
#include <sys/types.h>

typedef struct Flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int E;
  int T;
} flags;

int ReadFlags(int argc, char *argv[], flags *Flags);
int ReadFile(flags *Flags, char **argv);
// void Opt_b(FILE *f);
int is_regular_file(char *filename);