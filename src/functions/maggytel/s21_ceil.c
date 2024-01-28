#include "../../s21_math.h"

long double s21_ceil(double x) {
  long double res;
  if (x == S21_MAX_INF || x == S21_MIN_INF || x != x) {
    res = x;
  } else {
    long double buf = (long double)((long long)x);
    res = x - buf;
    if (res > 0.0)
      res = buf + 1;
    else
      res = buf;
  }
  return res;
}
