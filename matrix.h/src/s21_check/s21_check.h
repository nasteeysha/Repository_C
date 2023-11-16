#ifndef SRC_S21_CHECK_H_
#define SRC_S21_CHECK_H_

#include <check.h>
#include <stdlib.h>

void do_suite(Suite *suite, int *res);

Suite *s21_matrix_suite(void);

#endif  // SRC_S21_CHECK_H_