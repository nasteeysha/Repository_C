#include "s21_check.h"

#include <stdio.h>

void do_suite(Suite *suite, int *res) {
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  *res += srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int res = 0;
  do_suite(s21_matrix_suite(), &res);
  if (res) {
    printf("\e[0;31m");
  } else {
    printf("\e[0;32m");
  }
  return (res == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
