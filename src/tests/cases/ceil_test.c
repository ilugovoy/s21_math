#include "../s21_tests.h"

START_TEST(test_s21_ceil_1) {
  ck_assert_ldouble_eq(s21_ceil(-21.12345678912594), ceil(-21.12345678912594));
  ck_assert_ldouble_eq(s21_ceil(21.12345678912594), ceil(21.12345678912594));
}
END_TEST

START_TEST(test_s21_ceil_2) {
  ck_assert_ldouble_eq(s21_ceil(-0.21), ceil(-0.21));
  ck_assert_ldouble_eq(s21_ceil(0.21), ceil(0.21));
  ck_assert_ldouble_eq(s21_ceil(-0.5), ceil(-0.5));
  ck_assert_ldouble_eq(s21_ceil(-21), ceil(-21));
  ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(21), ceil(21));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
}
END_TEST

START_TEST(test_s21_ceil_3) {
  ck_assert_ldouble_eq(s21_ceil(S21_MAX_INF), ceil(S21_MAX_INF));
  ck_assert_ldouble_eq(s21_ceil(S21_MIN_INF), ceil(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_ceil(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_MIN_NAN));
}
END_TEST

Suite *test_s21_ceil_suite(void) {
  Suite *suite = suite_create("ceil_test");
  TCase *test_case = tcase_create("ceil_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_ceil_1);
    tcase_add_test(test_case, test_s21_ceil_2);
    tcase_add_test(test_case, test_s21_ceil_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
