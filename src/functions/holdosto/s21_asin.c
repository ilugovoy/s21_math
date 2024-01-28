#include "../../s21_math.h"

long double s21_asin(double x) {
  double eps = 0.0000000001;
  long double term = x, res = 0;
  if (x != x) {
    res = x;
  } else if (-1.0 < x && x < 1.0) {
    res = term;
    x *= x;
    for (int k = 1; s21_fabs((double)term) > eps; k += 2) {
      res += (term *= x * k / (k + 1)) / (k + 2);
    }
  } else if (x == 1.0)
    res = MY_PI_2;
  else if (x == -1.0)
    res = -MY_PI_2;
  else if (x > 1.0)
    res = S21_MAX_NAN;
  else if (x < -1.0)
    res = S21_MIN_NAN;
  return res;
}
