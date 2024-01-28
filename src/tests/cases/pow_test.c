#include "../s21_tests.h"

START_TEST(test_s21_pow_1) {
  ck_assert_ldouble_eq_tol(s21_pow(123.4567812345678, 2.1),
                           pow(123.4567812345678, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_2) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -0.5), pow(2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(S21_E, 21), pow(S21_E, 21), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 0.5), pow(2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2.1, 3), pow(-2.1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.1), pow(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -3), pow(2.1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.1), pow(0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 3), pow(2.1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_3) {
  ck_assert(isnan(s21_pow(-2.1, 1.8)) && isnan(pow(-2.1, 1.8)));
  ck_assert_ldouble_nan(s21_pow(S21_MAX_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MAX_INF, S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MIN_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MIN_INF, S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_pow(-123.4567812345678, 2.1));
}
END_TEST

Suite *test_s21_pow_suite(void) {
  Suite *suite = suite_create("pow_test");
  TCase *test_case = tcase_create("pow_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_pow_1);
    tcase_add_test(test_case, test_s21_pow_2);
    tcase_add_test(test_case, test_s21_pow_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
