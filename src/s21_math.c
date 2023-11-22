#include "s21_math.h"

#include <math.h>

// заменить все стандартные pow, fmod и тп на s21_***!!

//__fungusgr

int s21_abs(int x) {
  int res = x;
  if (res < 0)
    return -res;
  else
    return res;
}

long double s21_fabs(double x) {
  long double res = x;
  if (res == S21_MIN_NAN || res == S21_MAX_NAN)
    return S21_MAX_NAN;
  else if (res == 0)
    return 0;
  else if (res == S21_MAX_INF || res == S21_MIN_INF)
    return S21_MAX_INF;
  else
    return res < 0 ? -res : res;
}

//__maggytel

long double s21_ceil(double x) {
  long double res;
  if (x == S21_MAX_INF || x == S21_MIN_INF || x != x) {
    res = x;
  } else {
    long double buf = (long double)((long long)x);
    // позволяет сохранить целую часть числа с высокой точностью, подходящей для
    // вещественных чисел двойной точности
    res = x - buf;
    if (res > 0.0)
      res = buf + 1;
    else
      res = buf;
  }
  return res;
}

long double s21_floor(double x) {
  long double res;
  if (x == S21_MAX_INF || x == S21_MIN_INF || x != x) {
    res = x;
  } else {
    long double buf = (long double)((long long)x);
    res = x - buf;
    if (res >= 0.0)
      res = buf;
    else
      res = buf - 1;
  }
  return res;
}

//__holdosto

long double s21_sin(double x) {
  double eps = 1.0 / 1000000000000000.0;
  int sign = (x < 0) ? -1 : 1;
  x = fmod(s21_fabs(x), 2 * PI);
  if (x > PI) {
    x -= PI;
    sign *= -1;
  }
  if (x > PI / 2) x = PI - x;
  double t = x, res = x;
  for (int n = 3; s21_fabs(t) > eps; n += 2) {
    t = -t * x * x / n / (n - 1);
    res = res + t;
  }
  return res * sign;
}

long double s21_cos(double x) {
  double eps = 1.0 / 1000000000000000.0;
  x = fmod(s21_fabs(x), 2 * PI);
  double t = 1, res = 1;
  for (int n = 1; s21_fabs(t) > eps; n += 1) {
    t = -t * x * x / ((2 * n - 1) * (2 * n));
    res = res + t;
  }
  return res;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_asin(double x) {
  long double res = 0;
  if (x > -1 && x < 1)
    res = atan(x / sqrt(1 - pow(x, 2)));
  else if (x == 1)
    res = M_PI_2;
  else if (x == -1)
    res = -M_PI_2;
  else
    res = S21_MAX_NAN;
  return res;
}

long double s21_acos(double x) { return M_PI_2 - s21_asin(x); }

long double s21_atan(double x) {
  if (x == 0) return 0;
  if (x == S21_MAX_INF) return PI / 2;
  if (x == S21_MIN_INF) return -PI / 2;
  if (x > 0)
    return s21_asin(x / sqrt(1 + x * x));
  else
    return -s21_asin(-x / sqrt(1 + x * x));
}

//__shanikat

// long double exp(double x);
// long double pow(double base, double exp);
// long double fmod(double x, double y);

//__foldeslu

// long double sqrt(double x);
// long double log(double x);