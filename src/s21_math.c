#include "s21_math.h"

#include <math.h>
#include <stdbool.h>

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
  double eps = 0.0000000001;
  long double term = x, res = 0;
  if (x != x){
    res = S21_MAX_NAN;
  }
  else if (-1.0 < x && x < 1.0) {
    res = term;
    x *= x;
    for (int k = 1; s21_fabs((double)term) > eps; k += 2) {
      res += (term *= x * k / (k + 1)) / (k + 2);
    }
  } 
  else if (x == 1.0) res = M_PI_2;
  else if (x == -1.0) res = -M_PI_2;
  else if (x > 1.0) res = S21_MAX_NAN;
  else if (x < -1.0) res = S21_MIN_NAN;
  return res;
}

long double s21_acos(double x) { return M_PI_2 - s21_asin(x); }

long double s21_atan(double x) {
	double eps = 0.0000000001;
	long double result = 0;
	long double temp = 1;
	int flag = 1;
	int i = 0;
	if (x != x) result = x;
	if (s21_fabs(s21_fabs(x) - 1) < 1e-6) result = PI_4 * x;
	else if (x > -1 && x < 1) {
		while (s21_fabs(temp - result) > eps) {
		temp = result;
		result +=
			((pow(-1., i)) * (pow(x, (1. + (2. * i))))) / (1. + 2. * i);
		i++;
		}
	} 
	else if (x < -1 || x > 1) {
		long double res_tmp = 0;
		while (s21_fabs(temp - res_tmp) > eps || flag) {
		temp = res_tmp;
		res_tmp += ((pow(-1., i)) * (pow(x, (-1. - (2. * i))))) /
					(-1. - 2. * i);
		flag = 0;
		i++;
		}
		result = res_tmp + (PI * (sqrt(pow(x, 2.)))) / (2. * x);
	}
	if (x == 1.0 / 0.0) result = M_PI_2;
	if (x == -1.0 / 0.0) result = -M_PI_2;
	return result;
}


//__shanikat

long double s21_log(double x) {
  long double result = 0;
  double prev_result;
  int count = 0;

  if (x == S21_MAX_INF) result = x;
  else if (x == 0) result = S21_MIN_INF;
  else if (x < 0 || x == S21_MIN_INF) result = S21_MAX_NAN;
  else if (x != S21_MAX_INF && !(x < 0 || x == S21_MIN_INF)) {
    while (x >= S21_E) {
      x /= S21_E;
      count++;
    }
    for (int i = 1; i < 1000; i++) {
      prev_result = result;
      result = prev_result + 2 * (x - s21_exp(prev_result)) / (x + s21_exp(prev_result));
    }
    result += count;
  }
  return result;
}

long double s21_exp(double x) {
  bool flag = false;
  long double res = 1;
  if (x == S21_MAX_INF) {
    res = x;
    flag = true;
  }
  if (x == S21_MIN_INF) {
    res = 0;
    flag = true;
  }
  if (flag == false) {
    bool minus = false;
    if (x < 0) {
      x = -x;
      minus = true;
    }
    long double value = 1;
    long double i = 1;
    while (s21_fabs(value) > S21_MIN_E) {
      if (res > MAX_DOUBLE) {
        res = S21_MAX_INF;
        break;
      }
      value = value * (x / i);
      i++;
      res = res + value;
    }
    if (minus == true) {
      res = 1.0 / res;
    }
  }
  return res;
}

//__foldeslu

long double s21_fmod(double x, double y) {
  double result = 0.0;
  if (y == S21_MAX_INF || y == S21_MIN_INF) result = x;
  else if (y == S21_MAX_NAN || y == S21_MIN_NAN) result = S21_MAX_NAN;
  else {
    double quotient = x / y;
    double floor_quotient = (double)((long long)quotient);
    result = x - y * floor_quotient;
    if (x < 0 && result == 0) result = -result;
  }
  return result;
}

long double s21_pow(double x, double y) {
  long double result = 1.0;
  int z = y;
  if (y == 0) result = 1.0;
  else if (y > 0 && fmod(y, z) == 0) { //заменить на s21_fmod
    for (int i = 0; i < y; i++) {
      result *= x;
    }
  } 
  else if (y < 0 && fmod(y, z) == 0) { //заменить на s21_fmod
    y = -y;
    for (int i = 0; i < y; i++) {
      result *= x;
    }
    result = 1.0 / result;
  } 
  else {
    // result = s21_sqrt(x, y, 0.0000001);
    result = exp(y * log(x)); //заменить на s21_exp и s21_log
  }

  return result;
}

long double s21_sqrt(double x) {
  double guess = 0.0;
  if (x < 0) guess = S21_MAX_NAN;
  else {
    guess = x;
    while (fabs(guess * guess - x) > 0.00000001) { // s21_fabs
      guess = 0.5 * (guess + x / guess);
    }
  }
  return guess;
}
