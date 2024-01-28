#include "s21_tests.h"

int main(void) {
  size_t tests_failed = 0;

  Suite *abs_test_suite = test_s21_abs_suite();
  Suite *cos_test_suite = test_s21_cos_suite();
  Suite *exp_test_suite = test_s21_exp_suite();
  Suite *log_test_suite = test_s21_log_suite();
  Suite *pow_test_suite = test_s21_pow_suite();
  Suite *sin_test_suite = test_s21_sin_suite();
  Suite *tan_test_suite = test_s21_tan_suite();
  Suite *acos_test_suite = test_s21_acos_suite();
  Suite *asin_test_suite = test_s21_asin_suite();
  Suite *atan_test_suite = test_s21_atan_suite();
  Suite *ceil_test_suite = test_s21_ceil_suite();
  Suite *fmod_test_suite = test_s21_fmod_suite();
  Suite *sqrt_test_suite = test_s21_sqrt_suite();
  Suite *fabs_test_suite = test_s21_fabs_suite();
  Suite *floor_test_suite = test_s21_fabs_suite();

  SRunner *sr;
  sr = srunner_create(abs_test_suite);
  srunner_add_suite(sr, cos_test_suite);
  srunner_add_suite(sr, exp_test_suite);
  srunner_add_suite(sr, log_test_suite);
  srunner_add_suite(sr, pow_test_suite);
  srunner_add_suite(sr, sin_test_suite);
  srunner_add_suite(sr, tan_test_suite);
  srunner_add_suite(sr, acos_test_suite);
  srunner_add_suite(sr, asin_test_suite);
  srunner_add_suite(sr, atan_test_suite);
  srunner_add_suite(sr, ceil_test_suite);
  srunner_add_suite(sr, fmod_test_suite);
  srunner_add_suite(sr, sqrt_test_suite);
  srunner_add_suite(sr, fabs_test_suite);
  srunner_add_suite(sr, floor_test_suite);

  srunner_run_all(sr, CK_VERBOSE);
  tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
