#ifndef S21_MATH
#define S21_MATH

#define S21_MAX_INF ((1.0f) / (0.0f))
#define S21_MIN_INF ((-1.0f) / (0.0f))
#define S21_MAX_NAN ((0.0f) / (0.0f))
#define S21_MIN_NAN ((-0.0f) / (0.0f))

#define MAX_DOUBLE 1.7976931348623158e+308

#define S21_E 2.71828182845904523536028747
#define S21_MIN_E (1e-8)

#define PI (3.14159265358979323846264338327950288)
#define M_PI_2 ((PI) / (2.0))
#define PI_6 ((M_PI_2) / (3))
#define PI_56 ((M_PI_2) * (5))
#define PI_4 (PI / 4)
#define PI_3 ((PI) / (3))

#define EPS (1e-6)
#define EPS6 (1e-7)
#define EPS10 (0.0000000001)
#define EPS24 (1e-25)

//__fungusgr
int s21_abs(int x);
long double s21_fabs(double x);

//__maggytel
long double s21_ceil(double x);
long double s21_floor(double x);

//__holdosto
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

//__shanikat
long double s21_exp(double x);
// long double s21_trunc(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);

//__foldeslu
long double s21_sqrt(double x);
long double s21_log(double x);

#endif