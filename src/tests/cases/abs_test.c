#include "../s21_tests.h"

START_TEST(test_s21_abs_1) {
  ck_assert_int_eq(s21_abs((int)S21_MIN_INF), abs((int)S21_MIN_INF));
  ck_assert_int_eq(s21_abs((int)S21_MAX_INF), abs((int)S21_MAX_INF));
  ck_assert_int_eq(s21_abs((int)S21_MIN_NAN), abs((int)S21_MIN_NAN));
  ck_assert_int_eq(s21_abs((int)S21_MAX_NAN), abs((int)S21_MAX_NAN));
}
END_TEST

START_TEST(test_s21_abs_2) {
  ck_assert_int_eq(s21_abs(-42), abs(-42));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(42), abs(42));
  ck_assert_int_eq(s21_abs(0), abs(0));
}

Suite *test_s21_abs_suite(void) {
  Suite *suite = suite_create("abs_test");
  TCase *test_case = tcase_create("abs_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, test_s21_abs_1);
    tcase_add_test(test_case, test_s21_abs_2);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
