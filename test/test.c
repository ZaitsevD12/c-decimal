#include "test.h"

#include "../s21_decimal.h"

int main(void) {
  SRunner *sr;
  sr = srunner_create(NULL);
  srunner_add_suite(sr, suite_add());
  srunner_add_suite(sr, suite_sub());
  srunner_add_suite(sr, suite_mul());
  srunner_add_suite(sr, suite_div());
  srunner_add_suite(sr, suite_comp());
  srunner_add_suite(sr, suite_funcs());
  srunner_add_suite(sr, suite_pars());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
  return 0;
}