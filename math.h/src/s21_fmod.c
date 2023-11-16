#include "s21_math.h"

double s21_trunc(double d) { return (d > 0) ? s21_floor(d) : s21_ceil(d); }

long double s21_fmod(double x, double y) {
  long double result;
  if ((x != x) || y != y) {
    result = 0 / 0.0;
  } else if (x == 1. / 0.0 || y == 1. / 0.0) {
    result = 0. / 0.0;
  } else {
    if (x == 0) {
      result = 0;
    } else {
      result = (y == 0) ? 0 / 0.0 : (x - s21_trunc(x / y) * y);
    }
  }
  return result;
}