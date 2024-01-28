#include "../s21_tests.h"

START_TEST(test_s21_tan_1) {
  ck_assert_ldouble_eq_tol(s21_tan(-21.12345678912594), tan(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(21.12345678912594), tan(21.12345678912594),
                           1e-6);
}
END_TEST

START_TEST(test_s21_tan_2) {
  ck_assert_ldouble_eq_tol(s21_tan(-PI_3), tan(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI_6), tan(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI_6), tan(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI_3), tan(PI_3), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_3) {
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(2.1), tan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_4) {
  ck_assert_ldouble_nan(s21_tan(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_MIN_NAN));
}
END_TEST

Suite *test_s21_tan_suite(void) {
  Suite *suite = suite_create("tan_test");
  TCase *test_case = tcase_create("tan_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_tan_1);
    tcase_add_test(test_case, test_s21_tan_2);
    tcase_add_test(test_case, test_s21_tan_3);
    tcase_add_test(test_case, test_s21_tan_4);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
