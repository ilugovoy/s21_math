#include "s21_math.h"

#include <math.h>
#include <stdbool.h>

// заменить в pow, log на s21_log!!

//__fungusgr

int s21_abs(int x) {
  int res = x < 0 ? -x : x;
  return res;
}

long double s21_fabs(double x) {
  long double res;
  if (x == S21_MIN_NAN || x == S21_MAX_NAN)
    res = S21_MAX_NAN;
  else if (x == 0)
    res = 0;
  else if (x == S21_MAX_INF || x == S21_MIN_INF)
    res = S21_MAX_INF;
  else
    res = x < 0 ? -x : x;
  return res;
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
  x = s21_fmod(s21_fabs(x), 2 * MY_PI);  
  if (x > MY_PI) {
    x -= MY_PI;
    sign *= -1;
  }
  if (x > MY_PI / 2) x = MY_PI - x;
  double t = x, res = x;
  for (int n = 3; s21_fabs(t) > eps; n += 2) {
    t = -t * x * x / n / (n - 1);
    res = res + t;
  }
  return res * sign;
}

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

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

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

long double s21_acos(double x) { return MY_PI_2 - s21_asin(x); }

long double s21_atan(double x) {
  double eps = 0.0000000001;
  long double result = 0;
  long double temp = 1;
  int flag = 1;
  int i = 0;
  if (x != x) result = x;
  if (s21_fabs(s21_fabs(x) - 1) < 1e-6)
    result = PI_4 * x;
  else if (x > -1 && x < 1) {
    while (s21_fabs(temp - result) > eps) {
      temp = result;
      result += ((s21_pow(-1., i)) * (s21_pow(x, (1. + (2. * i))))) / (1. + 2. * i);
      i++;
    }
  } else if (x < -1 || x > 1) {
    long double res_tmp = 0;
    while (s21_fabs(temp - res_tmp) > eps || flag) {
      temp = res_tmp;
      res_tmp += ((s21_pow(-1., i)) * (s21_pow(x, (-1. - (2. * i))))) / (-1. - 2. * i);
      flag = 0;
      i++;
    }
    result = res_tmp + (MY_PI * (s21_sqrt(s21_pow(x, 2.)))) / (2. * x);
  }
  if (x == 1.0 / 0.0) result = MY_PI_2;
  if (x == -1.0 / 0.0) result = -MY_PI_2;
  return result;
}

//__shanikat

long double s21_log(double x) {
  long double result = 0;
  if (x == S21_MAX_INF)
    result = x;
  else if (x == 0)
    result = S21_MIN_INF;
  else if (x < 0 || x == S21_MIN_INF)
    result = S21_MAX_NAN;
  else if (x != S21_MAX_INF && !(x < 0 || x == S21_MIN_INF)) {
    double z = (x - 1) / (x + 1);
    for (int i = 1; i < 1000; i += 2) {
      result += s21_pow(z, i) / i;
    }
    result *= 2;
  }
  return result;
}

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

    while (result - last_result > 1e-6) {
      i++;
      last_result = result;
      result += s21_pow(x, i) / s21_factorial(i);
    }
    result = a < 0 ? 1 / result : result;
  }
  return result;
}

long double s21_factorial(double n) {
  if (n == 1)
    return 1;
  return s21_factorial(n - 1) * n;
}

//__foldeslu

// long double s21_fmod(double x, double y) {
//   double result = 0.0;
//   if (y == S21_MAX_INF || y == S21_MIN_INF)
//     result = x;
//   else if (y == S21_MAX_NAN || y == S21_MIN_NAN)
//     result = S21_MAX_NAN;
//   else {
//     double quotient = x / y;
//     double floor_quotient = (double)((long long)quotient);
//     result = x - y * floor_quotient;
//     if (x < 0 && result == 0) result = -result;
//   }
//   return result;
// }

long double s21_fmod(double x, double y) {
  long double result;
  if (y == S21_MAX_INF || y == S21_MIN_INF) result = x;
  else if (y == S21_MAX_NAN || y == S21_MIN_NAN) result = S21_MAX_NAN;
  else {
    long double quotient = x / y;
    long double fractional_part = s21_floor(quotient);
    result = x - (quotient < 0 ? s21_ceil(quotient) : fractional_part) * y;
  }
  return result;
}

long double s21_pow(double x, double y) {
  if (x < 0 && s21_fmod(y, 1) != 0) {
    return S21_MAX_NAN;
  } else {
    long double result = 1.0;
    int z = y;
    if (y == 0) {
      result = 1.0;
    } else if (y > 0 && s21_fmod(y, z) == 0) {
      for (int i = 0; i < y; i++) {
        result *= x;
      }
    } else if (y < 0 && s21_fmod(y, z) == 0) {
      y = -y;
      for (int i = 0; i < y; i++) {
        result *= x;
      }
      result = 1.0 / result;
    } else {
      result = s21_exp(y * log(x)); // если тут поставить s21_log то failed: s21_pow(666666.4, -1.5) == 4.72482e-06, pow(666666.4, -1.5) == 1.83712e-09, 1e-6
      	  								          // исправить точность
    }
    return result;
  }
}

long double s21_sqrt(double x) {
  double guess = 0.0;
  if (x < 0)
    guess = S21_MAX_NAN;
  else {
    guess = x;
    while (s21_fabs(guess * guess - x) > 0.00000001) { 
      guess = 0.5 * (guess + x / guess);
    }
  }
  return guess;
}
