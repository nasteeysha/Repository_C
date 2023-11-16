#include "s21_math.h"

long double s21_log(double x) {
  int ex_pow = 0;
  long double sum = 0;
  long double comp = 0;

  if (x != x) {
    sum = x;
  } else if (x == 1. / 0.0) {
    sum = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    sum = 0 / 0.;
  } else {
    if (x < 0) {
      sum = 0 / 0.0;
    } else if (x != 0) {
      for (; x >= 2.7182818284; x /= 2.7182818284, ex_pow++) continue;

      for (int i = 0; i < 100; i++) {
        comp = sum;
        sum = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
      }
    } else {
      sum = -1.0 / 0.0;
    }
  }
  return (sum + ex_pow);
}