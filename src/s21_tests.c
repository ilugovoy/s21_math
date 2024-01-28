#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(-21.12345678912594), sin(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(21.12345678912594), sin(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-MY_PI_2), sin(-MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(MY_PI_2), sin(MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_56), sin(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_3), sin(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_6), sin(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_56), sin(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_3), sin(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI_6), sin(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);

  ck_assert_ldouble_nan(s21_sin(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_sin(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(-21.12345678912594), cos(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(21.12345678912594), cos(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-MY_PI_2), cos(-MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(MY_PI_2), cos(MY_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_56), cos(-PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_3), cos(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_6), cos(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_56), cos(PI_56), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_6), cos(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI_3), cos(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2.1), cos(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);

  ck_assert_ldouble_nan(s21_cos(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_cos(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(-21.12345678912594), tan(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(21.12345678912594), tan(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI_3), tan(-PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI_6), tan(-PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI_6), tan(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI_3), tan(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(2.1), tan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);

  ck_assert_ldouble_nan(s21_tan(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.112345678912594),
                           asin(-0.112345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.112345678912594), asin(0.112345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);

  ck_assert_ldouble_nan(s21_asin(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_asin(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_asin(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_asin(-1.1));
  ck_assert_ldouble_nan(s21_asin(1.1));
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.112345678912594),
                           acos(-0.112345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.112345678912594), acos(0.112345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);

  ck_assert_ldouble_nan(s21_acos(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_acos(-1.1));
  ck_assert_ldouble_nan(s21_acos(1.1));
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(-21.12345678912594),
                           atan(-21.12345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(21.12345678912594), atan(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2.1), atan(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);

  ck_assert_ldouble_eq_tol(s21_atan(S21_MAX_INF), atan(S21_MAX_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_MIN_INF), atan(S21_MIN_INF), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_atan(S21_MAX_NAN));
}
END_TEST

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs((int)S21_MIN_INF), abs((int)S21_MIN_INF));
  ck_assert_int_eq(s21_abs((int)S21_MAX_INF), abs((int)S21_MAX_INF));
  ck_assert_int_eq(s21_abs((int)S21_MIN_NAN), abs((int)S21_MIN_NAN));
  ck_assert_int_eq(s21_abs((int)S21_MAX_NAN), abs((int)S21_MAX_NAN));

  ck_assert_int_eq(s21_abs(-42), abs(-42));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(42), abs(42));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_eq_tol(s21_fabs(-21.12345678912594),
                           fabs(-21.12345678912594), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(21.12345678912594), fabs(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(2.1), fabs(2.1), 1e-6);

  ck_assert_double_eq(s21_fabs(S21_MIN_INF), S21_MAX_INF);
  ck_assert_double_eq(s21_fabs(S21_MAX_INF), S21_MAX_INF);
  ck_assert_ldouble_nan(s21_fabs(S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_MAX_NAN));
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_eq(s21_ceil(-21.12345678912594), ceil(-21.12345678912594));
  ck_assert_ldouble_eq(s21_ceil(21.12345678912594), ceil(21.12345678912594));
  ck_assert_ldouble_eq(s21_ceil(-0.21), ceil(-0.21));
  ck_assert_ldouble_eq(s21_ceil(0.21), ceil(0.21));
  ck_assert_ldouble_eq(s21_ceil(-0.5), ceil(-0.5));
  ck_assert_ldouble_eq(s21_ceil(-21), ceil(-21));
  ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(21), ceil(21));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));

  ck_assert_ldouble_eq(s21_ceil(S21_MAX_INF), ceil(S21_MAX_INF));
  ck_assert_ldouble_eq(s21_ceil(S21_MIN_INF), ceil(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_ceil(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_ldouble_eq(s21_floor(-21.12345678912594),
                       s21_floor(-21.12345678912594));
  ck_assert_ldouble_eq(s21_floor(21.12345678912594),
                       s21_floor(21.12345678912594));
  ck_assert_ldouble_eq(s21_floor(-0.21), s21_floor(-0.21));
  ck_assert_ldouble_eq(s21_floor(0.21), s21_floor(0.21));
  ck_assert_ldouble_eq(s21_floor(-0.5), s21_floor(-0.5));
  ck_assert_ldouble_eq(s21_floor(-21), s21_floor(-21));
  ck_assert_ldouble_eq(s21_floor(0.5), s21_floor(0.5));
  ck_assert_ldouble_eq(s21_floor(-0), s21_floor(-0));
  ck_assert_ldouble_eq(s21_floor(21), s21_floor(21));
  ck_assert_ldouble_eq(s21_floor(0), s21_floor(0));

  ck_assert_ldouble_eq(s21_floor(S21_MAX_INF), floor(S21_MAX_INF));
  ck_assert_ldouble_eq(s21_floor(S21_MIN_INF), floor(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_floor(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(11.23456789125949), log(11.23456789125949),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(2.523), log(2.523), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MIN), log(DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(4.3234323e-43), log(4.3234323e-43), 1e-6);

  ck_assert_ldouble_nan(s21_log(-0.112345678912594));
  ck_assert_ldouble_infinite(s21_log(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_log(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_log(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_log(S21_MIN_NAN));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_nan(s21_log(-0.5));
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(-21.12345678912594), exp(-21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(21.12345678912594), exp(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-21.0), exp(-21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-5.0), exp(-5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(21.0), exp(21.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(2.1), exp(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(5.0), exp(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);

  ck_assert_ldouble_eq_tol(s21_exp(S21_MIN_INF), exp(S21_MIN_INF), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_exp(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_MAX_NAN));
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(123.4567812345678, 2.1),
                           pow(123.4567812345678, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -0.5), pow(2.1, -0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(S21_E, 21), pow(S21_E, 21), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 0.5), pow(2.1, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2.1, 3), pow(-2.1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.1), pow(-0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, -3), pow(2.1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.1), pow(0, 2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 3), pow(2.1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);

  ck_assert_ldouble_infinite(s21_pow(S21_MAX_INF, S21_MAX_INF));
  ck_assert(isnan(s21_pow(-2.1, 1.8)) && isnan(pow(-2.1, 1.8)));
  ck_assert_ldouble_nan(s21_pow(S21_MAX_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MAX_INF, S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MIN_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_MIN_INF, S21_MIN_NAN));
  ck_assert_ldouble_nan(s21_pow(-123.4567812345678, 2.1));
}
END_TEST

START_TEST(test_s21_fmod) {
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

  ck_assert_ldouble_eq_tol(s21_fmod(2.1, S21_MIN_INF), fmod(2.1, S21_MIN_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(2.1, S21_MIN_INF), fmod(2.1, S21_MIN_INF),
                           1e-6);
  ck_assert_ldouble_nan(s21_fmod(S21_MIN_INF, S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_MAX_INF, S21_MIN_NAN));
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(21.12345678912594), sqrt(21.12345678912594),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.0), sqrt(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.1), sqrt(2.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);

  ck_assert_ldouble_nan(s21_sqrt(-21.12345678912594));
  //   ck_assert_ldouble_infinite(s21_sqrt(S21_MAX_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_MAX_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_MIN_NAN));
}
END_TEST

Suite *math_suite(void) {
  Suite *test_suite;
  TCase *test_case;

  test_suite = suite_create("Math_functions");
  test_case = tcase_create("Math_function_tests");

  tcase_add_test(test_case, test_s21_floor);
  tcase_add_test(test_case, test_s21_fabs);
  tcase_add_test(test_case, test_s21_ceil);
  tcase_add_test(test_case, test_s21_asin);
  tcase_add_test(test_case, test_s21_acos);
  tcase_add_test(test_case, test_s21_atan);
  tcase_add_test(test_case, test_s21_fmod);
  tcase_add_test(test_case, test_s21_sqrt);
  tcase_add_test(test_case, test_s21_abs);
  tcase_add_test(test_case, test_s21_sin);
  tcase_add_test(test_case, test_s21_cos);
  tcase_add_test(test_case, test_s21_tan);
  tcase_add_test(test_case, test_s21_exp);
  tcase_add_test(test_case, test_s21_pow);
  tcase_add_test(test_case, test_s21_log);

  suite_add_tcase(test_suite, test_case);

  return test_suite;
}

int main(void) {
  int number_failed;
  Suite *test_suite;
  SRunner *sr;

  test_suite = math_suite();
  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
