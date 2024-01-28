#include "../s21_tests.h"

START_TEST(test_s21_sqrt_1) {
  ck_assert_ldouble_eq_tol(s21_sqrt(21.12345678912594), sqrt(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.0), sqrt(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.1), sqrt(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);

}
END_TEST

START_TEST(test_s21_sqrt_2) {

  ck_assert_ldouble_nan(s21_sqrt(-21.12345678912594));
  ck_assert_ldouble_nan(s21_sqrt(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_MIN_NAN));

}
END_TEST


Suite *test_s21_sqrt_suite(void) {
	
  Suite *suite = suite_create("sqrt_test");
  TCase *test_case = tcase_create("sqrt_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_sqrt_1);
    tcase_add_test(test_case, test_s21_sqrt_2);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
