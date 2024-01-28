#include "../s21_tests.h"

START_TEST(test_s21_sin_1) {
  ck_assert_ldouble_eq_tol(s21_sin(-21.12345678912594), sin(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(21.12345678912594), sin(21.12345678912594),
                           1e-6);
}
END_TEST

START_TEST(test_s21_sin_2) {
  ck_assert_ldouble_eq_tol(s21_sin(-MY_PI_2), sin(-MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(MY_PI_2), sin(MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_56), sin(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_3), sin(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_6), sin(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_56), sin(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_3), sin(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_6), sin(PI_6), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_3) {
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_4) {
  ck_assert_ldouble_nan(s21_sin(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_MIN_NAN));
}
END_TEST

Suite *test_s21_sin_suite(void) {
  Suite *suite = suite_create("sin_test");
  TCase *test_case = tcase_create("sin_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_sin_1);
    tcase_add_test(test_case, test_s21_sin_2);
    tcase_add_test(test_case, test_s21_sin_3);
    tcase_add_test(test_case, test_s21_sin_4);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
