#include "../../s21_math.h"

long double s21_atan(double x) {
  double eps = 0.0000000001;
  long double result = 0;
  long double temp = 1;
  int flag = 1;
  int i = 0;
  if (x != x)
    result = x;
  else if (x == 1.0 / 0.0)
    result = MY_PI_2;
  else if (x == -1.0 / 0.0)
    result = -MY_PI_2;
  else if (s21_fabs(s21_fabs(x) - 1) < 1e-6)
    result = PI_4 * x;
  else if (x > -1 && x < 1) {
    while (s21_fabs(temp - result) > eps) {
      temp = result;
      result +=
          ((s21_pow(-1., i)) * (s21_pow(x, (1. + (2. * i))))) / (1. + 2. * i);
      i++;
    }
  } else if (x < -1 || x > 1) {
    long double res_tmp = 0;
    while (s21_fabs(temp - res_tmp) > eps || flag) {
      temp = res_tmp;
      res_tmp +=
          ((s21_pow(-1., i)) * (s21_pow(x, (-1. - (2. * i))))) / (-1. - 2. * i);
      flag = 0;
      i++;
    }
    result = res_tmp + (MY_PI * (s21_sqrt(s21_pow(x, 2.)))) / (2. * x);
  }
  return result;
}
