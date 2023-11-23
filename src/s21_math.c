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

//__shanikat & foldeslu

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

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y < 0) y = -y;
  if (x != x || y != y || y == 0 || x == S21_MAX_INF || x == S21_MIN_INF) res = S21_MAX_NAN;
  else if (y == S21_MAX_INF || y == S21_MIN_INF) res = x;
  else {
    if (x == y) res = 0.;
    else if (x == -y) res = -0.;
    else if (x > 0) res = x - (s21_ceil(x / y) - 1.0) * y;
    else if (x < 0) res = x - (s21_ceil(x / y)) * y;  
  }
  return res;
}

// long double s21_pow(double base, double exp) {
// 	long double result = 0;
	
// 	if (base == S21_MIN_INF && exp == exp) {
// 		if (exp < 0) result = 0;
// 		else if (exp == 0) result = 1;
// 		else if (fmod(exp, 2) == 1)	result =  S21_MIN_INF;
// 		else result =  S21_MAX_INF;
// 	}
// 	else if (exp ==  S21_MIN_INF) {
// 		if (s21_fabs(base) == 1) result = 1;
// 		else result = 0;
// 	}
// 	else if (exp ==  S21_MAX_INF) {
// 		if (s21_fabs(base) == 1) result = 1;
// 		else result =  S21_MAX_INF;
// 	} 
// 	else if (exp == 0 || base == 1) result = 1;
// 	else if (base == -1) {
// 		if (exp ==  S21_MAX_INF || fmod(exp, 2) == 0) result = s21_fabs(base);
// 		else if (exp == (long long int)exp) result = base;
// 		else result =  S21_MAX_NAN;
// 	} 
// 	else if (base < 0 && !(base ==  S21_MIN_INF) && (exp != (long long int)exp && exp !=  S21_MAX_INF)) result =  S21_MAX_NAN;
// 	else result = s21_exp(s21_fabs(exp) * log(s21_fabs(base)));
// 	if (exp < 0) result = 1. / result;
// 	if (base < 0) {
// 		if (fmod(exp, 2) != 0) result = -result;
// 	}

// 	if (result ==  S21_MAX_INF) {
// 		if ((exp ==  S21_MAX_INF) || fmod(exp, 2) == 0 || exp != (long long int)exp) result = s21_fabs(result);
// 	}

// 	return result;
// }

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
  long double result;
  if (x < 0) result = S21_MAX_NAN;
  else result = s21_pow(x, 0.5);
  return result;
}

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