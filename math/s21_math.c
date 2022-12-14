#include "s21_math.h"

double s21_sin(double x) {
  double sum = 0, folding = 10, denominator = 1, num = 1, nominator = 1;
  int sign = 1;
  // scanf("%lf", &x);
  sum += x;
  nominator = x;
  while (fabs(folding) > EPSILON) {
    nominator *= pow(x, 2);
    sign *= -1;
    denominator *= (++num);
    denominator *= (++num);
    folding = sign * (nominator / denominator);
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
double s21_cos(double x) {
  double sum = 0, folding = 10, denominator = 1, num = 1, nominator = 1;
  int sign = 1;
  // scanf("%lf", &x);
  sum += 1;
  while (fabs(folding) > EPSILON) {
    nominator *= pow(x, 2);
    sign *= -1;
    denominator *= (++num);
    denominator *= (++num);
    folding = sign * (nominator / denominator);
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
// double s21_acos(double x) {}
double s21_asin(double x) {
  double sum = 0, folding = 10, denominator = 1, factorial = 1, koef = 3,
         num = 1, nominator = 1;
  int sign = 1;
  // scanf("%lf", &x);
  sum += x;
  nominator = x;
  while (fabs(folding) > EPSILON) {
    nominator *= pow(x, 2);
    sign *= -1;
    denominator *= 2 * factorial;
    folding = sign * (nominator / (denominator * koef++));
    koef++;
    factorial = factorial * ++num;
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
double s21_atan(double x) {
  double sum = 0, folding = 10, denominator = 1, nominator = 1;
  int sign = 1;
  // scanf("%lf", &x);
  sum += x;
  nominator = x;
  while (fabs(folding) > EPSILON) {
    nominator *= pow(x, 2);
    sign *= -1;
    denominator += 2;
    folding = sign * (nominator / denominator);
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }
int s21_abs(int x) { return x < 0 ? x * -1 : x; }
double s21_fabs(double x) { return x < 0 ? x * -1 : x; }
double s21_floor(double x) {
  double res = 0;
  // double diff = fabs(round(x) - x);
  if (round(x) < x)
    res = round(x);
  else {
    if (round(x) != x)
      res = round(x) - 1;
    else
      res = x;
  }
  return res;
}
double s21_ceil(double x) {
  double res = 0;
  // double diff = fabs(round(x) - x);
  if (round(x) < x)
    res = round(x) + 1;
  else {
    if (round(x) != x)
      res = round(x);
    else
      res = x;
  }
  return res;
}
long double s21_fmod(double x, double y) {
  double sum = x;
  while (fabs(sum) + y <= x) {
    sum += y;
  }
  return x - sum;
}
long double s21_log(double x) {
  double sum = 0, folding = 10, denominator = 1, nominator = 1;
  int sign = 1;
  // scanf("%lf", &x);
  x -= 1;
  sum += x;
  nominator = x;
  while (fabs(folding) > EPSILON) {
    nominator *= x;
    sign *= -1;
    folding = sign * (nominator / ++denominator);
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
long double s21_exp(double x) {
  double sum = 0, folding = 10, denominator = 1, num = 0, nominator = 1;
  // scanf("%lf", &x);
  sum += 1;
  while (fabs(folding) > EPSILON) {
    nominator *= x;
    denominator = denominator * ++num;
    folding = nominator / denominator;
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
long double s21_sqrt(double x) {
  double sum = 0, folding = 10, denominator = 1, num = 0, nominator = 1;
  // scanf("%lf", &x);
  sum += 1;
  while (fabs(folding) > EPSILON) {
    nominator *= x * (1 / 2 - num);
    denominator = denominator * ++num;
    folding = nominator / denominator;
    sum += folding;
    // printf("%lf  fold = %lf\n", sum, fabs(folding));
  }
  return sum;
}
long double s21_pow(double base, double exp) {
  for (double i = 0; i < exp; i++) {
    base *= base;
  }
  return base;
}
