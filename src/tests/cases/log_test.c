#include "../s21_tests.h"

START_TEST(test_s21_log_1) {
  ck_assert_ldouble_eq_tol(s21_log(11.23456789125949), log(11.23456789125949),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(2.523), log(2.523), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MIN), log(DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(4.3234323e-43), log(4.3234323e-43), 1e-6);
}
END_TEST

START_TEST(test_s21_log_2) {
  ck_assert_ldouble_nan(s21_log(-0.112345678912594));
  ck_assert_ldouble_nan(s21_log(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_log(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_log(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_log(-0.5));
}
END_TEST

Suite *test_s21_log_suite(void) {
  Suite *suite = suite_create("log_test");
  TCase *test_case = tcase_create("log_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_log_1);
    tcase_add_test(test_case, test_s21_log_2);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
