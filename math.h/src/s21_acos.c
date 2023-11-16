#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0.;
  if (x == 1 || x == -1) {
    result = S21_PI * (1 - x) / 2;
  } else if (x < -1 || x > 1) {
    result = 0 / 0.0;
  } else {
    result = (S21_PI / 2) - s21_asin(x);
  }
  return result;
}