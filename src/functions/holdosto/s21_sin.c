#include "../../s21_math.h"

long double s21_sin(double x) {
  double eps = 1.0 / 1000000000000000.0;
  int sign = (x < 0) ? -1 : 1;
  x = s21_fmod(s21_fabs(x), 2 * MY_PI);
  if (x > MY_PI / 2) x = MY_PI - x;
  double t = x, res = x;
  for (int n = 3; s21_fabs(t) > eps; n += 2) {
    t = -t * x * x / n / (n - 1);
    res = res + t;
  }
  return res * sign;
}
