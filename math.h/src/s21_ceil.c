#include "s21_math.h"

long double s21_ceil(double x) {
  double result;
  if (x != x) {
    result = x;
  } else if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = -1. / 0.0;
  } else {
    result = (x - (long long int)x != 0 && x > 0) ? (long long int)x + 1
                                                  : (long long int)x;
  }
  return result;
}
