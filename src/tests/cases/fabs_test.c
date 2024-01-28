#include "../s21_tests.h"

START_TEST(test_s21_fabs_1) {
  ck_assert_ldouble_eq_tol(s21_fabs(-21.12345678912594),
                           fabs(-21.12345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(21.12345678912594), fabs(21.12345678912594),
                           1e-6);
}
END_TEST

START_TEST(test_s21_fabs_2) {
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(2.1), fabs(2.1), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs_3) {
  ck_assert_double_eq(s21_fabs(S21_MIN_INF), S21_MAX_INF);
  ck_assert_double_eq(s21_fabs(S21_MAX_INF), S21_MAX_INF);
  ck_assert_ldouble_nan(s21_fabs(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_MAX_NAN));
}
END_TEST

Suite *test_s21_fabs_suite(void) {
  Suite *suite = suite_create("fabs_test");
  TCase *test_case = tcase_create("fabs_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_fabs_1);
    tcase_add_test(test_case, test_s21_fabs_2);
    tcase_add_test(test_case, test_s21_fabs_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
