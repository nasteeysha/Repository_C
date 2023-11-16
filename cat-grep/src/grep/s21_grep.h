#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int s;
  int f;
  int h;
  int o;
  int noOpt;
  int notOneFile;
} flags;

int ReadFlags(int argc, char **argv, flags *Flags);
int ReadFile(flags Flags, char *pattern, char *file);