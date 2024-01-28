#include "../s21_tests.h"

START_TEST(test_s21_acos_1) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.112345678912594),
                           acos(-0.112345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.112345678912594), acos(0.112345678912594),
                           1e-6);
}

END_TEST

START_TEST(test_s21_acos_2) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
}
END_TEST

START_TEST(test_s21_acos_3) {
  ck_assert_ldouble_nan(s21_acos(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_acos(-1.1));
  ck_assert_ldouble_nan(s21_acos(1.1));
}
END_TEST

Suite *test_s21_acos_suite(void) {
  Suite *suite = suite_create("acos_test");
  TCase *test_case = tcase_create("acos_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_acos_1);
    tcase_add_test(test_case, test_s21_acos_2);
    tcase_add_test(test_case, test_s21_acos_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}