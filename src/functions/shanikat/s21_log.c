#include "../../s21_math.h"

// Need to fix it
// Test number: 10, name: log
// Test result for the function s21_log: FAIL
// Memory test: OK
// Test result: 0

void s21_log_normalize(double *x, int *power) {
  *power = 0;
  while (*x > 10) {
    *power += 1;
    *x /= 10;
  }
  while (*x < 1) {
    *power -= 1;
    *x *= 10;
  }
}

long double s21_log(double x) {
  long double result = 0;
  if (x == S21_MAX_INF)
    result = x;
  else if (x == 0)
    result = S21_MIN_INF;
  else if (x < 0 || x == S21_MIN_INF)
    result = S21_MAX_NAN;
  else if (x != S21_MAX_INF && !(x < 0 || x == S21_MIN_INF)) {
    int ten = 0;
    s21_log_normalize(&x, &ten);
    long double z = (x - 1) / (x + 1);
    long double slagaemoe = z;
    result = z;
    z = s21_pow(z, 2);
    for (int i = 3; i < 6500; i += 2) {  // самый кринжовый момент)
      slagaemoe *= z * (i - 2) / i;
      result += slagaemoe;
    }
    result *= 2;
    result += ten * S21_LN10;
  }
  return result;
}
