#include "../../s21_math.h"

long double s21_pow(double x, double y) {
  long double result = 1.0;
  if (x < 0 && s21_fmod(y, 1) != 0) {
    result = S21_MAX_NAN;
  } else {
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
      result = s21_exp(y * s21_log(x));
    }
  }
  return result;
}
