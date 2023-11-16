#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("")
#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

#define S21_NEGZERO -0.0

#define S21_E 2.718281828459045
#define S21_PI 3.141592653589793
#define s21_EPS 1e-17

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
/*  возвращает ближайшее целое число, не меньшее заданного значения */
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
/*  вычисляет абсолютное значение числа с плавающей точкой */
long double s21_fabs(double x);
/*  возвращает ближайшее целое число, не превышающее заданное значение */
long double s21_floor(double x);
/*  остаток операции деления с плавающей точкой */
long double s21_fmod(double x, double y);
double s21_trunc(double d);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
#endif  //  SRC_S21_MATH_H_