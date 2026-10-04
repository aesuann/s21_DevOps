#ifndef CAT_S21_CAT_H_
#define CAT_S21_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flag {
  int b;  // (GNU: --number-nonblank) | нумерует только непустые строки |
  int e;  // предполагает и -v | также отображает символы конца строки как $  |
  int n;  // (GNU: --number) | нумерует все выходные строки |
  int s;  // (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
  int t;  // предполагает и -v | также отображает табы как ^I |
  int v;  // Отображает unprintable символы
} flags;

int parser(int argc, char *argv[], flags *flag);
void reader(char *argv[], flags *flag);

#endif  // CAT_S21_CAT_H_