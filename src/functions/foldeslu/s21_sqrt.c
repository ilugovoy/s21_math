#include "../../s21_math.h"

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
