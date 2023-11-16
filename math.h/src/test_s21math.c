#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_ceil_f) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_ceil(value1), ceil(value1));
  double value2 = 0.45;
  ck_assert_uint_eq(s21_ceil(value2), ceil(value2));
  double value3 = -3.01;
  ck_assert_uint_eq(s21_ceil(value3), ceil(value3));
  double value4 = -0;
  ck_assert_uint_eq(s21_ceil(value4), ceil(value4));
  double value5 = 1234567;
  ck_assert_uint_eq(s21_ceil(value5), ceil(value5));
}
END_TEST

START_TEST(s21_floor_f) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_floor(value1), floor(value1));
  double value2 = 0.45;
  ck_assert_uint_eq(s21_floor(value2), floor(value2));
  double value3 = -3.01;
  ck_assert_uint_eq(s21_floor(value3), floor(value3));
  double value4 = -0.;
  ck_assert_uint_eq(s21_floor(value4), floor(value4));
  double value5 = -0;
  ck_assert_uint_eq(s21_floor(value5), floor(value5));
}
END_TEST

START_TEST(s21_tan_f) {
  double value1 = 0.23;
  ck_assert_int_eq(s21_tan(value1), tan(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_tan(value2), tan(value2));
  double value3 = -1234567;
  ck_assert_int_eq(s21_tan(value3), tan(value3));
  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
}
END_TEST

START_TEST(s21_cos_f) {
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(s21_sin_f) {
  double value1 = 0;
  ck_assert_int_eq(s21_sin(value1), sin(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_sin(value2), sin(value2));
  double value3 = -3234567;
  ck_assert_int_eq(s21_sin(value3), sin(value3));
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_int_eq(s21_sin(i), sin(i));
  }
}
END_TEST

START_TEST(s21_abs_f) {
  int value1 = -4;
  ck_assert_int_eq(s21_abs(value1), abs(value1));
  int value2 = -123;
  ck_assert_int_eq(s21_abs(value2), abs(value2));
  for (int i = -1234567; i < 123456; i += 10) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
}
END_TEST

START_TEST(s21_atan_f) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_atan(value1), atan(value1));
  double value2 = 0.12;
  ck_assert_int_eq(s21_atan(value2), atan(value2));
  double value3 = 1;
  ck_assert_int_eq(s21_atan(value3), atan(value3));
  double value4 = -1;
  ck_assert_int_eq(s21_atan(value4), atan(value4));
  double value5 = 0;
  ck_assert_int_eq(s21_atan(value5), atan(value5));
  double value6 = 12345;
  ck_assert_int_eq(s21_atan(value6), atan(value6));
  double value7 = 0.001;
  ck_assert_int_eq(s21_atan(value7), atan(value7));
  double value8 = -12345;
  ck_assert_int_eq(s21_atan(value8), atan(value8));
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_int_eq(s21_atan(i), atan(i));
  }
}
END_TEST

START_TEST(s21_acos_f) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_acos(value1), acos(value1));
  double value2 = -1;
  ck_assert_int_eq(s21_acos(value2), acos(value2));
  double value3 = -0.999;
  ck_assert_int_eq(s21_acos(value3), acos(value3));
  for (double i = -10.; i < 10.; i += 1.) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }
  for (double i = -1; i < 1; i += 0.01) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }
}
END_TEST

START_TEST(s21_asin_f) {
  ck_assert_int_eq(asin(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asin(13.54), s21_asin(13.54));
  ck_assert_int_eq(asin(6.28), s21_asin(6.28));

  ck_assert_float_eq(asin(0.1234), s21_asin(0.1234));
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq(asin(1), s21_asin(1));
  ck_assert_float_eq(asin(-1), s21_asin(-1));
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(s21_fmod_f) {
  ck_assert_int_eq(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7));
  ck_assert_int_eq(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1));
  ck_assert_int_eq(s21_fmod(23.456, 4.355), fmod(23.456, 4.355));
}
END_TEST

START_TEST(s21_exp_f) {
  ck_assert_float_eq(exp(13.54), s21_exp(13.54));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_ldouble_eq(exp(-INFINITY), s21_exp(-INFINITY));
}
END_TEST

START_TEST(s21_log_f) {
  ck_assert_int_eq(s21_log(12356), log(12356));
  ck_assert_int_eq(s21_log(1.1), log(1.1));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

START_TEST(s21_sqrt_f) {
  ck_assert_int_eq(s21_sqrt(16.0), sqrt(16.0));
  ck_assert_int_eq(s21_sqrt(45.35), sqrt(45.35));
  ck_assert_int_eq(s21_sqrt(5.0), sqrt(5.0));
  for (double i = -1.; i < 100000; i += 10) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
}
END_TEST

START_TEST(s21_pow_f) {
  ck_assert_float_eq(pow(13.21313, 2.5), s21_pow(13.21313, 2.5));
  ck_assert_float_eq(pow(32346234.21313, 2.5), s21_pow(32346234.21313, 2.5));
  ck_assert_float_eq(pow(0, 2.5), s21_pow(0, 2.5));
  ck_assert_float_eq(pow(2, 18.1), s21_pow(2, 18.1));
  ck_assert_float_eq(pow(123, -2), s21_pow(123, -2));
  ck_assert_float_eq(pow(123, 2), s21_pow(123, 2));
  ck_assert_float_eq(pow(123, 0), s21_pow(123, 0));
  ck_assert_int_eq(pow(-12.1, -1.1), s21_pow(-12.1, -1.1));
  ck_assert_double_nan(s21_pow(-12.1, -1.1));
  ck_assert_double_nan(s21_pow(-12.1, 1.1));
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
  ck_assert_ldouble_eq(pow(INFINITY, 1), s21_pow(INFINITY, 1));
  ck_assert_ldouble_eq(pow(-INFINITY, 1), s21_pow(-INFINITY, 1));
  ck_assert_ldouble_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fabs_f) {
  ck_assert_uint_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_uint_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_uint_eq(s21_fabs(1.0), fabs(1.0));
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Func Check");

  TCase *tc_ceil;
  TCase *tc_floor;
  TCase *tc_tan;
  TCase *tc_cos;
  TCase *tc_sin;
  TCase *tc_abs;
  TCase *tc_atan;
  TCase *tc_acos;
  TCase *tc_asin;
  TCase *tc_fmod;
  TCase *tc_exp;
  TCase *tc_log;
  TCase *tc_sqrt;
  TCase *tc_pow;
  TCase *tc_fabs;

  tc_fabs = tcase_create("Fabs func");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_f);

  tc_pow = tcase_create("Pow func");
  suite_add_tcase(s, tc_pow);
  tcase_add_test(tc_pow, s21_pow_f);

  tc_sqrt = tcase_create("Sqrt func");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_f);

  tc_log = tcase_create("Log func");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_f);

  tc_exp = tcase_create("Exp func");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_f);

  tc_fmod = tcase_create("Fmod func");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_f);

  tc_asin = tcase_create("Asin func");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_f);

  tc_acos = tcase_create("Acos func");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_f);

  tc_atan = tcase_create("Atan func");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_f);

  tc_abs = tcase_create("Abs func");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_f);

  tc_sin = tcase_create("Sin func");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_f);

  tc_cos = tcase_create("Cos func");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_f);

  tc_tan = tcase_create("Tan func");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_f);

  tc_floor = tcase_create("Floor func");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_f);

  tc_ceil = tcase_create("Ceil func");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_f);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}
