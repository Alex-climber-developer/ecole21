#include "s21_math.h"
double my_inf = 1.0 / 0.0;
double my_min_inf = -1.0 / 0.0;
double my_nan = 0.0 / 0.0;
double min_nan = -0.0 / 0.0;
double zero = 0;
double min_zero = -0;
double small_num = 1;
double min_small_num = -1;
double num = 100;
double min_num = -100;
double big_num = 666666;
double min_big_num = -666666;
double zf = 0.5;
double mzf = -0.5;
double tf = 2.5;
double mtf = -2.5;
double big_float = 1234.456789;
double min_big_float = -1234.456789;
double small = 0.0000001;
double min_small = -0.0000001;
double long_double = 0.3425443513423432432432;
double min_long_double;
int flag = 0;
double x;
double y;
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
long double s21_exp(double x) {  //! FIXME: smaaall and big value dont work
  double sum = 0, folding = 10, denominator = 1, num = 0, nominator = 1;
  if (x == my_inf)
    sum = my_inf;
  else if (x == my_min_inf)
    sum = 0;
  else if (x == my_nan)
    sum = my_nan;
  else {
    sum += 1;
    while (fabs(folding) > EPSILON) {
      nominator *= x;
      denominator = denominator * ++num;
      folding = nominator / denominator;
      sum += folding;
      // printf("%lf  fold = %lf\n", sum, fabs(folding));
    }
  }
  return sum;
}
long double s21_sqrt(double x) {  //! FIXME: dont work
  double sum = 0, folding = 10, denominator = 1, num = 0, nominator = 1,
         half = 0.5;
  if (x == my_inf)
    sum = my_inf;
  else if (x == my_min_inf)
    sum = my_nan;
  else if (x == my_nan)
    sum = my_nan;
  else if (x == 0)
    sum = 0;
  else {
    // scanf("%lf", &x);
    sum += 1;
    x -= 1;
    while (fabs(folding) > EPSILON) {
      nominator *= x;
      // nominator = nominator * 0.5* sign;  //?
      denominator = denominator * ++num;
      folding = nominator / denominator;
      sum += folding;
      // printf("%lf  fold = %lf\n", sum, fabs(folding));
    }
  }
  return sum;
}
long double s21_pow(double base, double exp) {  // TODO: try tests  - surprize
  if (base == my_inf)
    base = 1;
  else if (base == my_min_inf)
    base = 0;
  else if (base == zero)
    base = my_inf;
  else {
    for (double i = 1; i < fabs(exp); i++) {
      base *= base;
    }
    if (exp < 0) base = 1 / base;
  }
  return base;
}

int main() {
  double s = s21_fmod(1, -2);
  double f = fmod(1, -2);
  printf("my: %f\norig: %f\n", s, f);
}