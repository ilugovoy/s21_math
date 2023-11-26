#ifndef S21_MATH
#define S21_MATH

// Определения для минус бесконечности, плюс бесконечности, NaN (не числовое
// значение)
#define S21_MIN_INF ((-1.0f) / (0.0f))
#define S21_MIN_NAN ((-0.0f) / (0.0f))
#define S21_MAX_INF ((1.0f) / (0.0f))
#define S21_MAX_NAN ((0.0f) / (0.0f))

// Максимальное значение для типа double
#define MAX_DOUBLE 1.7976931348623158e+308

// Число e (основание натурального логарифма) и минимальное значение для e
#define S21_E 2.71828182845904523536028747
#define S21_MIN_E (1e-8)

// Число π и его деления
#define MY_PI (3.14159265358979323846264338327950288)
#define MY_PI_2 ((MY_PI) / (2.0))
#define PI_6 ((MY_PI_2) / (3))
#define PI_56 ((MY_PI_2) * (5))
#define PI_3 ((MY_PI) / (3))
#define PI_4 (MY_PI / 4)

// Различные значения для погрешностей/эпсилон
#define EPS10 (0.0000000001)
#define EPS24 (1e-25)
#define EPS6 (1e-7)
#define EPS (1e-6)

//__fungusgr
long double s21_fabs(double x);
int s21_abs(int x);

//__maggytel
long double s21_floor(double x);
long double s21_ceil(double x);

//__holdosto
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

//__shanikat
long double s21_exp(double x);
long double s21_log(double x);

//__foldeslu
long double s21_pow(double base, double exp);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);

#endif
