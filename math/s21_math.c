#include "s21_math.h"
double s21_PI = 3.1415926535897932384626433832;
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
double min_long_double = -0.3425443513423432432432;
int flag = 0;
double x;
double y;

double s21_round_pi(double x) {
  if (x > 0)
    while (fabs(x) > s21_PI) x = x - (2 * s21_PI);
  else
    while (fabs(x) > s21_PI) x = x + (2 * s21_PI);

  return x;
}
double s21_round_pi2(double x) {
  if (x > 0)
    while (fabs(x) > s21_PI / 2) x = x - (s21_PI);
  else
    while (fabs(x) > s21_PI / 2) x = x + (s21_PI);
  return x;
}

double s21_sin(double x) {  //* GOOD
  double sum = 0, folding = 10, denominator = 1, num = 1, nominator = 1;
  int sign = 1;
  if (x == my_nan || x == my_min_inf || x == my_inf || x == min_nan)
    sum = my_nan;
  else {
    x = s21_round_pi(x);
    sum += x;
    nominator = x;
    while (fabs(folding) > EPSILON) {
      nominator *= pow(x, 2);
      sign *= -1;
      denominator *= (++num);
      denominator *= (++num);
      folding = sign * (nominator / denominator);
      sum += folding;
    }
  }
  return sum;
}
double s21_cos(double x) {  //* GOOD
  double sum = 0, folding = 10, denominator = 1, num = 0, nominator = 1;
  int sign = 1;
  if (x == my_nan || x == my_min_inf || x == my_inf || x == min_nan)
    sum = my_nan;
  else {
    x = s21_round_pi(x);
    sum += 1;
    while (fabs(folding) > EPSILON) {
      nominator *= pow(x, 2);
      sign *= -1;
      denominator *= (++num);
      denominator *= (++num);
      folding = sign * (nominator / denominator);
      sum += folding;
    }
  }
  return sum;
}
// double s21_acos(double x) {}
double s21_asin(
    double x) {  //! считает верно но последние знаки не точны(не те)
  double sum = 0, folding = 10, denominator = 1, factorial = 1, koef = 3,
         num = 1, nominator = 1;
  if (x == my_nan || x == my_min_inf || x == my_inf || x == min_nan)
    sum = my_nan;
  else if (fabs(x) > 1) {
    sum = my_nan;
  } else {
    sum += x;
    nominator = x;
    while (fabs(folding) > EPSILON) {
      nominator = nominator * pow(x, 2) * (koef - 2);
      denominator = denominator * 2 * factorial;
      folding = nominator / (denominator * koef++);
      koef++;
      factorial = factorial * ++num;
      sum += folding;
    }
  }
  return sum;
}
double s21_atan(double x) {  //! не верно
  double sum = 0, folding = 10, denominator = 1, nominator = 1;
  int sign = 1;
  if (x == my_nan || x == min_nan)
    sum = my_nan;
  else if (x == my_min_inf)
    sum = -1.570796;
  else if (x == my_inf)
    sum = 1.570796;
  else {
    sum += x;
    nominator = x;
    while (fabs(folding) > EPSILON) {
      nominator *= pow(x, 2);
      sign *= -1;
      denominator += 2;
      folding = sign * (nominator / denominator);
      sum += folding;
    }
  }

  return sum;
}
double s21_tan(double x) {  //* GOOD
  double sum = 0;
  if (x == my_nan || x == my_min_inf || x == my_inf || x == min_nan)
    sum = my_nan;
  else {
    x = s21_round_pi2(x);
    sum = s21_sin(x) / s21_cos(x);
  }
  return sum;
}
int s21_abs(int x) {  //* GOOD
  return x < 0 ? x * -1 : x;
}
double s21_fabs(double x) {  //* GOOD
  return x < 0 ? x * -1 : x;
}
double s21_floor(double x) {  //* GOOD
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
double s21_ceil(double x) {  //* GOOD
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
long double s21_fmod(
    double x,
    double y) {  //? FIX TEST: func good work but test not work with sycle
                 // (when nan - ck_assert_ldouble_nan, when num -
                 // ck_assert_double_eq_tol)
  double sum = 0;
  if (x == my_min_inf)
    sum = my_nan;
  else if (y == 0)
    sum = my_nan;
  else if (x == 0)
    sum = 0;
  else if (x == 1) {
    if (fabs(y) <= 1)
      sum = 0;
    else
      sum = 1;
  } else if (x <= y && x > 0) {
    sum = x;
  } else if (x > y && x < 0) {
    sum = x;
  } else {
    // y = fabs(y);
    while (fabs(sum) + fabs(y) <= fabs(x)) {
      if (x > 0 && y < 0)
        sum -= (y);
      else
        sum += (y);
    }
    sum = x - sum;
  }
  return sum;
}
long double s21_log(double x) {  //! растет с каждой итерацией - не сходится
                                 //! (хотя по формуле верно)
  double sum = 0, folding = 10, denominator = 1, nominator = 1;
  int sign = 1;
  if (x == zero)
    sum = -1 * my_inf;
  else if (x < 0)
    sum = my_nan;
  // else if (y == 0)
  //   sum = my_nan;
  // else if (x == 0)
  //   sum = 0;
  // else if (x == 1) {
  // }
  else {
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

// int main() {
//   // for (double i = -2; i < 3; i += 0.5) {
//   //   // printf("my =%f\n", s21_fmod(zero, i));
//   //   printf("or= %f\n\n", fmod(min_small_num, i));
//   //   //   // if ((float)fmod(min_num, i) == (float)s21_fmod(min_num, i))
//   //   //   //   printf("Yes\n");
//   //   //   // else
//   //   //   // printf("No\n");
//   //   //   printf("i = %f\n", i);

//   //   //   printf("+: %f\n-: %f\n\n", fmod(min_num, i), s21_fmod(min_num,
//   // i));
//   // }

//   // printf("+: %f\n", (atan(mzf)));
//   // printf("-: %f\n\n", (s21_atan(mzf)));
//   // printf("+: %f\n", (atan(zf)));
//   // printf("-: %f\n\n", (s21_atan(zf)));
//   // printf("+: %f\n", (atan(min_long_double)));
//   // printf("-: %f\n\n", (s21_atan(min_long_double)));

//   // printf("+: %f\n", (atan(long_double)));
//   // printf("-: %f\n\n", (s21_atan(long_double)));

//   // printf("+: %f\n", (asin(min_small_num))) ;
//   // printf("-: %f\n\n", (s21_asin(min_small_num)));

//   // printf("+: %f\n", (asin(small_num)));
//   // printf("-: %f\n\n", (s21_asin(small_num)));
//   // printf("-: %f\n", (s21_sin(100)));

//   printf("+: %f\n", (atan(num)));
//   printf("+: %f\n\n", (s21_atan(num)));

//   printf("+: %f\n", (atan(min_num)));
//   printf("+: %f\n\n", (s21_atan(min_num)));

//   printf("+: %f\n", (atan(big_num)));
//   printf("+: %f\n\n", (s21_atan(big_num)));

//   // printf("+: %f\n", (atan(my_min_inf)));
//   // printf("+: %f\n\n", (s21_atan(my_min_inf)));
//   // double i = 3;
//   // printf("+: %f\n-: %f\n", fmod(i, i - 2.1), s21_fmod(i, i - 2.1));
//   // printf("+: %f\n-: %f\n", fmod(3, 5.1), s21_fmod(3, 5.1));
//   // printf("+: %f\n-: %f\n", fmod(3., 3.), s21_fmod(3., 3.));

//   // double s = s21_fmod(5, -2);
//   // double f = fmod(5, -2);
//   // printf("my: %f\norig: %f\n", s, f);
//   return 0;
// }