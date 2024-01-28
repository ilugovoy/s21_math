#include "../s21_tests.h"

START_TEST(test_s21_atan_1) {
  ck_assert_ldouble_eq_tol(s21_atan(-21.12345678912594),
                           atan(-21.12345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(21.12345678912594), atan(21.12345678912594),
                           1e-6);
}
END_TEST

START_TEST(test_s21_atan_2) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2.1), atan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
}
END_TEST

START_TEST(test_s21_atan_3) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_MAX_INF), atan(S21_MAX_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_MIN_INF), atan(S21_MIN_INF), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_atan(S21_MAX_NAN));
}
END_TEST

Suite *test_s21_atan_suite(void) {
  Suite *suite = suite_create("atan_test");
  TCase *test_case = tcase_create("atan_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_atan_1);
    tcase_add_test(test_case, test_s21_atan_2);
    tcase_add_test(test_case, test_s21_atan_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}