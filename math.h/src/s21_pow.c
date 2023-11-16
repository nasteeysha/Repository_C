#include "s21_math.h"

long double s21_pow(double b, double exp) {
  long double result = b;
  if (b != 1) {
    if ((b != b) || exp != exp) {
      result = 0 / 0.0;
    } else if (b == 1. / 0.0 || exp == 1. / 0.0) {
      result = 1. / 0.0;
    } else {
      if (b == 0) {
        result = 0;
      } else {
        if (exp - (long long int)exp == 0) {
          if (exp > 0) {
            for (int i = 1; i < exp; i++) {
              result *= b;
            }
          } else if (exp < 0) {
            exp *= -1;
            for (int i = 1; i < exp; i++) {
              result *= b;
            }
            result = 1 / result;
          } else {
            result = 1;
          }
        } else {
          if (exp < 0 || b < 0) {
            result = 0. / 0.;
          } else

            result = s21_exp(exp * s21_log(b));
        }
      }
    }
  }
  return result;
}