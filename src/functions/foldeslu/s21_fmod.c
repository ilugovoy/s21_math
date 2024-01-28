#include "../../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (y == S21_MAX_INF || y == S21_MIN_INF)
    result = x;
  else if (y != y)
    result = y;
  else {
    long double quotient = x / y;
    long double fractional_part = s21_floor(quotient);
    result = x - (quotient < 0 ? s21_ceil(quotient) : fractional_part) * y;
  }
  return result;
}
