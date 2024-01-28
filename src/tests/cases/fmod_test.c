#include "../s21_tests.h"

START_TEST(test_s21_fmod_1) {
  ck_assert_ldouble_eq_tol(s21_fmod(123.4567812345678, 2.1),
                           fmod(123.4567812345678, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(666667.5, 1.5), fmod(666667.5, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-4.2, -21.2), fmod(-4.2, -21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.1, -0.5), fmod(-2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(4.2, -21.2), fmod(4.2, -21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, -0.5), fmod(2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.1, 0.5), fmod(-2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(4.2, 21.2), fmod(4.2, 21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, 0.5), fmod(2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 2.1), fmod(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 2.1), fmod(0, 2.1), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_2) {
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, S21_MIN_INF), fmod(2.1, S21_MIN_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, S21_MIN_INF), fmod(2.1, S21_MIN_INF),
                           1e-6);
  ck_assert_ldouble_nan(s21_fmod(S21_MIN_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_MAX_INF, S21_MIN_NAN));
}
END_TEST

Suite *test_s21_fmod_suite(void) {
  Suite *suite = suite_create("fmod_test");
  TCase *test_case = tcase_create("fmod_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_fmod_1);
    tcase_add_test(test_case, test_s21_fmod_2);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
