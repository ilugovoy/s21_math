#include "../s21_tests.h"

START_TEST(test_s21_cos_1) {
  ck_assert_ldouble_eq_tol(s21_cos(-MY_PI_2), cos(-MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(MY_PI_2), cos(MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_56), cos(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_3), cos(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_6), cos(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_56), cos(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_6), cos(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_3), cos(PI_3), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_2) {
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2.1), cos(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_3) {
  ck_assert_ldouble_nan(s21_cos(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_MIN_NAN));
}
END_TEST

Suite *test_s21_cos_suite(void) {
  Suite *suite = suite_create("sum_test");
  TCase *test_case = tcase_create("sum_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_cos_1);
    tcase_add_test(test_case, test_s21_cos_2);
    tcase_add_test(test_case, test_s21_cos_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}