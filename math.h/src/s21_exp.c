#include "s21_math.h"

long double s21_exp(double x) {
  int counter = 2;
  long double sum, factorial, number = x;
  factorial = number;
  sum = 1.0;
  if (x != x) {
    sum = x;
  } else if (x == 1. / 0.0) {
    sum = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    sum = 0;
  } else {
    while (s21_fabs((double)factorial) > 0.000000000001) {
      sum += factorial;
      factorial *= number / counter;
      counter++;
    }
  }
  return sum;
}