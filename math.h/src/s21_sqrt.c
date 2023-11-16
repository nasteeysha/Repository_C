#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0.0 / 0.;
  if (x == 1. / 0.) {
    res = 1. / 0.;
  } else if (x >= 0) {
    res = 1.0;
    for (int i = 0; i < 100; i++) {
      res -= (res * res - x) / (2 * res);
    }
  }
  return res;
}