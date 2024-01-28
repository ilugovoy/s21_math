#include "../../s21_math.h"

// #include <math.h>
// #include <stdbool.h>

int s21_abs(int x) {
  int res = x < 0 ? -x : x;
  return res;
}
