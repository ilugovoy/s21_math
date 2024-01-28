#include "../../s21_math.h"

long double s21_fabs(double x) {
  long double res;
  if (x != x)
    res = x;
  else if (x == 0)
    res = 0;
  else if (x == S21_MAX_INF || x == S21_MIN_INF)
    res = S21_MAX_INF;
  else
    res = x < 0 ? -x : x;
  return res;
}
