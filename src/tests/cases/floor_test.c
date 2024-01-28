#include "../s21_tests.h"

// START_TEST(test_s21_floor_1) {

//   ck_assert_ldouble_eq(s21_floor(-21.12345678912594),s21_floor(-21.12345678912594));
//   ck_assert_ldouble_eq(s21_floor(21.12345678912594),s21_floor(21.12345678912594));

// }
// END_TEST

START_TEST(test_s21_floor_2) {
  ck_assert_ldouble_eq(s21_floor(-0.21), s21_floor(-0.21));
  ck_assert_ldouble_eq(s21_floor(0.21), s21_floor(0.21));
  ck_assert_ldouble_eq(s21_floor(-0.5), s21_floor(-0.5));
  ck_assert_ldouble_eq(s21_floor(-21), s21_floor(-21));
  ck_assert_ldouble_eq(s21_floor(0.5), s21_floor(0.5));
  ck_assert_ldouble_eq(s21_floor(-0), s21_floor(-0));
  ck_assert_ldouble_eq(s21_floor(21), s21_floor(21));
  ck_assert_ldouble_eq(s21_floor(0), s21_floor(0));
}
END_TEST

START_TEST(test_s21_floor_3) {
  ck_assert_ldouble_eq(s21_floor(S21_MAX_INF), floor(S21_MAX_INF));
  ck_assert_ldouble_eq(s21_floor(S21_MIN_INF), floor(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_floor(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_MIN_NAN));
}
END_TEST

Suite *test_s21_floor_suite(void) {
  Suite *suite = suite_create("floor_test");
  TCase *test_case = tcase_create("floor_test");

  if (suite != NULL && test_case != NULL) {
    // tcase_add_test(test_case, test_s21_floor_1);
    tcase_add_test(test_case, test_s21_floor_2);
    tcase_add_test(test_case, test_s21_floor_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
