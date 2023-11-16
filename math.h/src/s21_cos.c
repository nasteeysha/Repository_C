#include "s21_math.h"

long double s21_two_factorial(int x) {
  long double result = 1;
  for (int n = 1; n <= x; n++) {
    result *= n;
  }
  return result;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  long double k = -1;
  long double d = 0;
  int n = 1;
  long double pow = x * x;
  long double sum = 1;

  if (x != x) {
    sum = x;
  } else if (x == 1. / 0.0) {
    sum = 0. / 0.0;
  } else {
    do {
      sum += d;
      d = (k * pow) / s21_two_factorial(2 * n);
      n++;
      k *= -1;
      pow *= x * x;
    } while (s21_fabs(d) > 0.0000000000000001);
  }
  return sum;
}