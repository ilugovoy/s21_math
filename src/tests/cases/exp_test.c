#include "../s21_tests.h"

START_TEST(test_s21_exp_1) {
  ck_assert_ldouble_eq_tol(s21_exp(-21.12345678912594), exp(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(21.12345678912594), exp(21.12345678912594),
                           1e-6);
}
END_TEST

START_TEST(test_s21_exp_2) {
  ck_assert_ldouble_eq_tol(s21_exp(-21.0), exp(-21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-5.0), exp(-5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(21.0), exp(21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(2.1), exp(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(5.0), exp(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_3) {
  ck_assert_ldouble_eq_tol(s21_exp(S21_MIN_INF), exp(S21_MIN_INF), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_exp(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_MAX_NAN));
}
END_TEST

Suite *test_s21_exp_suite(void) {
  Suite *suite = suite_create("acos_test");
  TCase *test_case = tcase_create("acos_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_exp_1);
    tcase_add_test(test_case, test_s21_exp_2);
    tcase_add_test(test_case, test_s21_exp_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
