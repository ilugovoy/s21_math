#include "../../s21_math.h"

long double s21_exp(double x) {
  bool flag = false;
  long double result = 1;
  if (x == S21_MAX_INF) {
    result = x;
    flag = true;
  }
  if (x == S21_MIN_INF) {
    result = 0;
    flag = true;
  }
  if (flag == false) {
    double a = x;
    x = s21_fabs(x);
    int i = 0;
    long double last_result = 0;
    long double value = 1;
    while (result - last_result > 1e-6) {
      i++;
      last_result = result;
      value = value * x / i;
      result += value;
    }
    result = a < 0 ? 1 / result : result;
  }
  return result;
}
