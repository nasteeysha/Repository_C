#include "s21_math.h"

long double s21_atan(double x) {
  int sign = x < 0 ? -1 : 1;
  long double result = sign * s21_acos(1. / (s21_pow(1 + x * x, 0.5)));
  return result;
}