#include "../../s21_math.h"

long double s21_cos(double x) {
  double eps = 1.0 / 1000000000000000.0;
  x = s21_fmod(s21_fabs(x), 2 * MY_PI);
  double t = 1, res = 1;
  for (int n = 1; s21_fabs(t) > eps; n += 1) {
    t = -t * x * x / ((2 * n - 1) * (2 * n));
    res = res + t;
  }
  return res;
}
