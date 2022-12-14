
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.c"
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
double min_long_double = -0.3425443513423432432432;
int flag = 0;
double x;
double y;
// char str1[100] = {'\0'};
// char str2[100] = {'\0'};

START_TEST(abs_test) {
  ck_assert_int_eq(s21_abs(my_inf), abs(my_inf));
  ck_assert_int_eq(s21_abs(my_min_inf), abs(my_min_inf));
  ck_assert_int_eq(s21_abs(my_nan), abs(my_nan));
  ck_assert_int_eq(s21_abs(min_nan), abs(min_nan));
  ck_assert_int_eq(s21_abs(zero), abs(zero));
  ck_assert_int_eq(s21_abs(min_zero), abs(min_zero));
  ck_assert_int_eq(s21_abs(big_num), abs(big_num));
  ck_assert_int_eq(s21_abs(min_big_num), abs(min_big_num));
  ck_assert_int_eq(s21_abs(num), abs(num));
  ck_assert_int_eq(s21_abs(min_num), abs(min_num));
  ck_assert_int_eq(s21_abs(small_num), abs(small_num));
  ck_assert_int_eq(s21_abs(min_small_num), abs(min_small_num));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(s21_fabs(my_inf), fabs(my_inf));
  ck_assert_double_eq(s21_fabs(my_min_inf), fabs(my_min_inf));
  ck_assert_double_eq(s21_fabs(my_nan), fabs(my_nan));
  ck_assert_double_eq(s21_fabs(min_nan), fabs(min_nan));
  ck_assert_double_eq(s21_fabs(zero), fabs(zero));
  ck_assert_double_eq(s21_fabs(min_zero), fabs(min_zero));
  ck_assert_double_eq(s21_fabs(min_small_num), fabs(min_small_num));
  ck_assert_double_eq(s21_fabs(small_num), fabs(small_num));
  ck_assert_double_eq(s21_fabs(num), fabs(num));
  ck_assert_double_eq(s21_fabs(min_num), fabs(min_num));
  ck_assert_double_eq(s21_fabs(big_num), fabs(big_num));
  ck_assert_double_eq(s21_fabs(min_big_num), fabs(min_big_num));
  ck_assert_double_eq(s21_fabs(mzf), fabs(mzf));
  ck_assert_double_eq(s21_fabs(tf), fabs(tf));
  ck_assert_double_eq(s21_fabs(mtf), fabs(mtf));
  ck_assert_double_eq(s21_fabs(big_float), fabs(big_float));
  ck_assert_double_eq(s21_fabs(big_float), fabs(big_float));
  ck_assert_double_eq(s21_fabs(min_big_float), fabs(min_big_float));
  ck_assert_double_eq(s21_fabs(small), fabs(small));
  ck_assert_double_eq(s21_fabs(min_long_double), fabs(min_long_double));
  ck_assert_double_eq(s21_fabs(min_small), fabs(min_small));
  ck_assert_double_eq(s21_fabs(long_double), fabs(long_double));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(s21_floor(my_inf), floor(my_inf));
  ck_assert_double_eq(s21_floor(my_min_inf), floor(my_min_inf));
  ck_assert_double_eq(s21_floor(my_nan), floor(my_nan));
  ck_assert_double_eq(s21_floor(min_nan), floor(min_nan));
  ck_assert_double_eq(s21_floor(zero), floor(zero));
  ck_assert_double_eq(s21_floor(min_zero), floor(min_zero));
  ck_assert_double_eq(s21_floor(min_small_num), floor(min_small_num));
  ck_assert_double_eq(s21_floor(small_num), floor(small_num));
  ck_assert_double_eq(s21_floor(num), floor(num));
  ck_assert_double_eq(s21_floor(min_num), floor(min_num));
  ck_assert_double_eq(s21_floor(big_num), floor(big_num));
  ck_assert_double_eq(s21_floor(min_big_num), floor(min_big_num));
  ck_assert_double_eq(s21_floor(mzf), floor(mzf));
  ck_assert_double_eq(s21_floor(tf), floor(tf));
  ck_assert_double_eq(s21_floor(mtf), floor(mtf));
  ck_assert_double_eq(s21_floor(big_float), floor(big_float));
  ck_assert_double_eq(s21_floor(big_float), floor(big_float));
  ck_assert_double_eq(s21_floor(min_big_float), floor(min_big_float));
  ck_assert_double_eq(s21_floor(small), floor(small));
  ck_assert_double_eq(s21_floor(min_long_double), floor(min_long_double));
  ck_assert_double_eq(s21_floor(min_small), floor(min_small));
  ck_assert_double_eq(s21_floor(long_double), floor(long_double));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_double_eq(s21_ceil(my_inf), ceil(my_inf));
  ck_assert_double_eq(s21_ceil(my_min_inf), ceil(my_min_inf));
  ck_assert_double_eq(s21_ceil(my_nan), ceil(my_nan));
  ck_assert_double_eq(s21_ceil(min_nan), ceil(min_nan));
  ck_assert_double_eq(s21_ceil(zero), ceil(zero));
  ck_assert_double_eq(s21_ceil(min_zero), ceil(min_zero));
  ck_assert_double_eq(s21_ceil(min_small_num), ceil(min_small_num));
  ck_assert_double_eq(s21_ceil(small_num), ceil(small_num));
  ck_assert_double_eq(s21_ceil(num), ceil(num));
  ck_assert_double_eq(s21_ceil(min_num), ceil(min_num));
  ck_assert_double_eq(s21_ceil(big_num), ceil(big_num));
  ck_assert_double_eq(s21_ceil(min_big_num), ceil(min_big_num));
  ck_assert_double_eq(s21_ceil(mzf), ceil(mzf));
  ck_assert_double_eq(s21_ceil(tf), ceil(tf));
  ck_assert_double_eq(s21_ceil(mtf), ceil(mtf));
  ck_assert_double_eq(s21_ceil(big_float), ceil(big_float));
  ck_assert_double_eq(s21_ceil(big_float), ceil(big_float));
  ck_assert_double_eq(s21_ceil(min_big_float), ceil(min_big_float));
  ck_assert_double_eq(s21_ceil(small), ceil(small));
  ck_assert_double_eq(s21_ceil(min_long_double), ceil(min_long_double));
  ck_assert_double_eq(s21_ceil(min_small), ceil(min_small));
  ck_assert_double_eq(s21_ceil(long_double), ceil(long_double));
}
END_TEST

START_TEST(exp_test) {
  ck_assert_double_eq(s21_exp(my_inf), exp(my_inf));
  ck_assert_double_eq(s21_exp(my_min_inf), exp(my_min_inf));
  ck_assert_double_eq(s21_exp(my_nan), exp(my_nan));
  ck_assert_double_eq(s21_exp(min_nan), exp(min_nan));
  ck_assert_double_eq(s21_exp(zero), exp(zero));
  ck_assert_double_eq(s21_exp(min_zero), exp(min_zero));
  ck_assert_double_eq(s21_exp(min_small_num), exp(min_small_num));
  ck_assert_double_eq(s21_exp(small_num), exp(small_num));
  ck_assert_double_eq(s21_exp(num), exp(num));
  ck_assert_double_eq(s21_exp(min_num), exp(min_num));
  ck_assert_double_eq(s21_exp(big_num), exp(big_num));
  ck_assert_double_eq(s21_exp(min_big_num), exp(min_big_num));
  ck_assert_double_eq(s21_exp(mzf), exp(mzf));
  ck_assert_double_eq(s21_exp(tf), exp(tf));
  ck_assert_double_eq(s21_exp(mtf), exp(mtf));
  ck_assert_double_eq(s21_exp(big_float), exp(big_float));
  ck_assert_double_eq(s21_exp(big_float), exp(big_float));
  ck_assert_double_eq(s21_exp(min_big_float), exp(min_big_float));
  ck_assert_double_eq(s21_exp(small), exp(small));
  ck_assert_double_eq(s21_exp(min_long_double), exp(min_long_double));
  ck_assert_double_eq(s21_exp(min_small), exp(min_small));
  ck_assert_double_eq(s21_exp(long_double), exp(long_double));
}
END_TEST

START_TEST(pow_test) {
  for (double i = -2; i < 3; i++) {
    ck_assert_double_eq(s21_pow(my_inf, i), pow(my_inf, i));
    ck_assert_double_eq(s21_pow(my_min_inf, i), pow(my_min_inf, i));
    ck_assert_double_eq(s21_pow(my_nan, i), pow(my_nan, i));
    ck_assert_double_eq(s21_pow(min_nan, i), pow(min_nan, i));
    ck_assert_double_eq(s21_pow(zero, i), pow(zero, i));
    ck_assert_double_eq(s21_pow(min_zero, i), pow(min_zero, i));
    ck_assert_double_eq(s21_pow(min_small_num, i), pow(min_small_num, i));
    ck_assert_double_eq(s21_pow(small_num, i), pow(small_num, i));
    ck_assert_double_eq(s21_pow(num, i), pow(num, i));
    ck_assert_double_eq(s21_pow(min_num, i), pow(min_num, i));
    ck_assert_double_eq(s21_pow(big_num, i), pow(big_num, i));
    ck_assert_double_eq(s21_pow(min_big_num, i), pow(min_big_num, i));
    ck_assert_double_eq(s21_pow(mzf, i), pow(mzf, i));
    ck_assert_double_eq(s21_pow(tf, i), pow(tf, i));
    ck_assert_double_eq(s21_pow(mtf, i), pow(mtf, i));
    ck_assert_double_eq(s21_pow(big_float, i), pow(big_float, i));
    ck_assert_double_eq(s21_pow(big_float, i), pow(big_float, i));
    ck_assert_double_eq(s21_pow(min_big_float, i), pow(min_big_float, i));
    ck_assert_double_eq(s21_pow(small, i), pow(small, i));
    ck_assert_double_eq(s21_pow(min_long_double, i), pow(min_long_double, i));
    ck_assert_double_eq(s21_pow(min_small, i), pow(min_small, i));
    ck_assert_double_eq(s21_pow(long_double, i), pow(long_double, i));
  }
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_double_eq(s21_sqrt(my_inf), sqrt(my_inf));
  ck_assert_double_eq(s21_sqrt(my_min_inf), sqrt(my_min_inf));
  ck_assert_double_eq(s21_sqrt(my_nan), sqrt(my_nan));
  ck_assert_double_eq(s21_sqrt(min_nan), sqrt(min_nan));
  ck_assert_double_eq(s21_sqrt(zero), sqrt(zero));
  ck_assert_double_eq(s21_sqrt(min_zero), sqrt(min_zero));
  ck_assert_double_eq(s21_sqrt(min_small_num), sqrt(min_small_num));
  ck_assert_double_eq(s21_sqrt(small_num), sqrt(small_num));
  ck_assert_double_eq(s21_sqrt(num), sqrt(num));
  ck_assert_double_eq(s21_sqrt(min_num), sqrt(min_num));
  ck_assert_double_eq(s21_sqrt(big_num), sqrt(big_num));
  ck_assert_double_eq(s21_sqrt(min_big_num), sqrt(min_big_num));
  ck_assert_double_eq(s21_sqrt(mzf), sqrt(mzf));
  ck_assert_double_eq(s21_sqrt(tf), sqrt(tf));
  ck_assert_double_eq(s21_sqrt(mtf), sqrt(mtf));
  ck_assert_double_eq(s21_sqrt(big_float), sqrt(big_float));
  ck_assert_double_eq(s21_sqrt(big_float), sqrt(big_float));
  ck_assert_double_eq(s21_sqrt(min_big_float), sqrt(min_big_float));
  ck_assert_double_eq(s21_sqrt(small), sqrt(small));
  ck_assert_double_eq(s21_sqrt(min_long_double), sqrt(min_long_double));
  ck_assert_double_eq(s21_sqrt(min_small), sqrt(min_small));
  ck_assert_double_eq(s21_sqrt(long_double), sqrt(long_double));
}
END_TEST

START_TEST(fmod_test) {
  for (double i = -2; i < 3; i += 0.5) {
    ck_assert_double_eq(s21_fmod(my_inf, i), fmod(my_inf, i));
    ck_assert_double_eq(s21_fmod(my_min_inf, i), fmod(my_min_inf, i));
    ck_assert_double_eq(s21_fmod(my_nan, i), fmod(my_nan, i));
    ck_assert_double_eq(s21_fmod(min_nan, i), fmod(min_nan, i));
    ck_assert_double_eq(s21_fmod(zero, i), fmod(zero, i));
    ck_assert_double_eq(s21_fmod(min_zero, i), fmod(min_zero, i));
    ck_assert_double_eq(s21_fmod(min_small_num, i), fmod(min_small_num, i));
    ck_assert_double_eq(s21_fmod(small_num, i), fmod(small_num, i));
    ck_assert_double_eq(s21_fmod(num, i), fmod(num, i));
    ck_assert_double_eq(s21_fmod(min_num, i), fmod(min_num, i));
    ck_assert_double_eq(s21_fmod(big_num, i), fmod(big_num, i));
    ck_assert_double_eq(s21_fmod(min_big_num, i), fmod(min_big_num, i));
    ck_assert_double_eq(s21_fmod(mzf, i), fmod(mzf, i));
    ck_assert_double_eq(s21_fmod(tf, i), fmod(tf, i));
    ck_assert_double_eq(s21_fmod(mtf, i), fmod(mtf, i));
    ck_assert_double_eq(s21_fmod(big_float, i), fmod(big_float, i));
    ck_assert_double_eq(s21_fmod(big_float, i), fmod(big_float, i));
    ck_assert_double_eq(s21_fmod(min_big_float, i), fmod(min_big_float, i));
    ck_assert_double_eq(s21_fmod(small, i), fmod(small, i));
    ck_assert_double_eq(s21_fmod(min_long_double, i), fmod(min_long_double, i));
    ck_assert_double_eq(s21_fmod(min_small, i), fmod(min_small, i));
    ck_assert_double_eq(s21_fmod(long_double, i), fmod(long_double, i));
  }
}
END_TEST

START_TEST(log_test) {
  ck_assert_double_eq(s21_log(my_inf), log(my_inf));
  ck_assert_double_eq(s21_log(my_min_inf), log(my_min_inf));
  ck_assert_double_eq(s21_log(my_nan), log(my_nan));
  ck_assert_double_eq(s21_log(min_nan), log(min_nan));
  ck_assert_double_eq(s21_log(zero), log(zero));
  ck_assert_double_eq(s21_log(min_zero), log(min_zero));
  ck_assert_double_eq(s21_log(min_small_num), log(min_small_num));
  ck_assert_double_eq(s21_log(small_num), log(small_num));
  ck_assert_double_eq(s21_log(num), log(num));
  ck_assert_double_eq(s21_log(min_num), log(min_num));
  ck_assert_double_eq(s21_log(big_num), log(big_num));
  ck_assert_double_eq(s21_log(min_big_num), log(min_big_num));
  ck_assert_double_eq(s21_log(mzf), log(mzf));
  ck_assert_double_eq(s21_log(tf), log(tf));
  ck_assert_double_eq(s21_log(mtf), log(mtf));
  ck_assert_double_eq(s21_log(big_float), log(big_float));
  ck_assert_double_eq(s21_log(big_float), log(big_float));
  ck_assert_double_eq(s21_log(min_big_float), log(min_big_float));
  ck_assert_double_eq(s21_log(small), log(small));
  ck_assert_double_eq(s21_log(min_long_double), log(min_long_double));
  ck_assert_double_eq(s21_log(min_small), log(min_small));
  ck_assert_double_eq(s21_log(long_double), log(long_double));
}
END_TEST

START_TEST(sin_test) {
  ck_assert_double_eq(s21_sin(my_inf), sin(my_inf));
  ck_assert_double_eq(s21_sin(my_min_inf), sin(my_min_inf));
  ck_assert_double_eq(s21_sin(my_nan), sin(my_nan));
  ck_assert_double_eq(s21_sin(min_nan), sin(min_nan));
  ck_assert_double_eq(s21_sin(zero), sin(zero));
  ck_assert_double_eq(s21_sin(min_zero), sin(min_zero));
  ck_assert_double_eq(s21_sin(min_small_num), sin(min_small_num));
  ck_assert_double_eq(s21_sin(small_num), sin(small_num));
  ck_assert_double_eq(s21_sin(num), sin(num));
  ck_assert_double_eq(s21_sin(min_num), sin(min_num));
  ck_assert_double_eq(s21_sin(big_num), sin(big_num));
  ck_assert_double_eq(s21_sin(min_big_num), sin(min_big_num));
  ck_assert_double_eq(s21_sin(mzf), sin(mzf));
  ck_assert_double_eq(s21_sin(tf), sin(tf));
  ck_assert_double_eq(s21_sin(mtf), sin(mtf));
  ck_assert_double_eq(s21_sin(big_float), sin(big_float));
  ck_assert_double_eq(s21_sin(big_float), sin(big_float));
  ck_assert_double_eq(s21_sin(min_big_float), sin(min_big_float));
  ck_assert_double_eq(s21_sin(small), sin(small));
  ck_assert_double_eq(s21_sin(min_long_double), sin(min_long_double));
  ck_assert_double_eq(s21_sin(min_small), sin(min_small));
  ck_assert_double_eq(s21_sin(long_double), sin(long_double));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_double_eq(s21_cos(my_inf), cos(my_inf));
  ck_assert_double_eq(s21_cos(my_min_inf), cos(my_min_inf));
  ck_assert_double_eq(s21_cos(my_nan), cos(my_nan));
  ck_assert_double_eq(s21_cos(min_nan), cos(min_nan));
  ck_assert_double_eq(s21_cos(zero), cos(zero));
  ck_assert_double_eq(s21_cos(min_zero), cos(min_zero));
  ck_assert_double_eq(s21_cos(min_small_num), cos(min_small_num));
  ck_assert_double_eq(s21_cos(small_num), cos(small_num));
  ck_assert_double_eq(s21_cos(num), cos(num));
  ck_assert_double_eq(s21_cos(min_num), cos(min_num));
  ck_assert_double_eq(s21_cos(big_num), cos(big_num));
  ck_assert_double_eq(s21_cos(min_big_num), cos(min_big_num));
  ck_assert_double_eq(s21_cos(mzf), cos(mzf));
  ck_assert_double_eq(s21_cos(tf), cos(tf));
  ck_assert_double_eq(s21_cos(mtf), cos(mtf));
  ck_assert_double_eq(s21_cos(big_float), cos(big_float));
  ck_assert_double_eq(s21_cos(big_float), cos(big_float));
  ck_assert_double_eq(s21_cos(min_big_float), cos(min_big_float));
  ck_assert_double_eq(s21_cos(small), cos(small));
  ck_assert_double_eq(s21_cos(min_long_double), cos(min_long_double));
  ck_assert_double_eq(s21_cos(min_small), cos(min_small));
  ck_assert_double_eq(s21_cos(long_double), cos(long_double));
}
END_TEST

START_TEST(tan_test) {
  ck_assert_double_eq(s21_tan(my_inf), tan(my_inf));
  ck_assert_double_eq(s21_tan(my_min_inf), tan(my_min_inf));
  ck_assert_double_eq(s21_tan(my_nan), tan(my_nan));
  ck_assert_double_eq(s21_tan(min_nan), tan(min_nan));
  ck_assert_double_eq(s21_tan(zero), tan(zero));
  ck_assert_double_eq(s21_tan(min_zero), tan(min_zero));
  ck_assert_double_eq(s21_tan(min_small_num), tan(min_small_num));
  ck_assert_double_eq(s21_tan(small_num), tan(small_num));
  ck_assert_double_eq(s21_tan(num), tan(num));
  ck_assert_double_eq(s21_tan(min_num), tan(min_num));
  ck_assert_double_eq(s21_tan(big_num), tan(big_num));
  ck_assert_double_eq(s21_tan(min_big_num), tan(min_big_num));
  ck_assert_double_eq(s21_tan(mzf), tan(mzf));
  ck_assert_double_eq(s21_tan(tf), tan(tf));
  ck_assert_double_eq(s21_tan(mtf), tan(mtf));
  ck_assert_double_eq(s21_tan(big_float), tan(big_float));
  ck_assert_double_eq(s21_tan(big_float), tan(big_float));
  ck_assert_double_eq(s21_tan(min_big_float), tan(min_big_float));
  ck_assert_double_eq(s21_tan(small), tan(small));
  ck_assert_double_eq(s21_tan(min_long_double), tan(min_long_double));
  ck_assert_double_eq(s21_tan(min_small), tan(min_small));
  ck_assert_double_eq(s21_tan(long_double), tan(long_double));
}
END_TEST

START_TEST(asin_test) {
  ck_assert_double_eq(s21_asin(my_inf), asin(my_inf));
  ck_assert_double_eq(s21_asin(my_min_inf), asin(my_min_inf));
  ck_assert_double_eq(s21_asin(my_nan), asin(my_nan));
  ck_assert_double_eq(s21_asin(min_nan), asin(min_nan));
  ck_assert_double_eq(s21_asin(zero), asin(zero));
  ck_assert_double_eq(s21_asin(min_zero), asin(min_zero));
  ck_assert_double_eq(s21_asin(min_small_num), asin(min_small_num));
  ck_assert_double_eq(s21_asin(small_num), asin(small_num));
  ck_assert_double_eq(s21_asin(num), asin(num));
  ck_assert_double_eq(s21_asin(min_num), asin(min_num));
  ck_assert_double_eq(s21_asin(big_num), asin(big_num));
  ck_assert_double_eq(s21_asin(min_big_num), asin(min_big_num));
  ck_assert_double_eq(s21_asin(mzf), asin(mzf));
  ck_assert_double_eq(s21_asin(tf), asin(tf));
  ck_assert_double_eq(s21_asin(mtf), asin(mtf));
  ck_assert_double_eq(s21_asin(big_float), asin(big_float));
  ck_assert_double_eq(s21_asin(big_float), asin(big_float));
  ck_assert_double_eq(s21_asin(min_big_float), asin(min_big_float));
  ck_assert_double_eq(s21_asin(small), asin(small));
  ck_assert_double_eq(s21_asin(min_long_double), asin(min_long_double));
  ck_assert_double_eq(s21_asin(min_small), asin(min_small));
  ck_assert_double_eq(s21_asin(long_double), asin(long_double));
}
END_TEST

START_TEST(atan_test) {
  ck_assert_double_eq(s21_atan(my_inf), atan(my_inf));
  ck_assert_double_eq(s21_atan(my_min_inf), atan(my_min_inf));
  ck_assert_double_eq(s21_atan(my_nan), atan(my_nan));
  ck_assert_double_eq(s21_atan(min_nan), atan(min_nan));
  ck_assert_double_eq(s21_atan(zero), atan(zero));
  ck_assert_double_eq(s21_atan(min_zero), atan(min_zero));
  ck_assert_double_eq(s21_atan(min_small_num), atan(min_small_num));
  ck_assert_double_eq(s21_atan(small_num), atan(small_num));
  ck_assert_double_eq(s21_atan(num), atan(num));
  ck_assert_double_eq(s21_atan(min_num), atan(min_num));
  ck_assert_double_eq(s21_atan(big_num), atan(big_num));
  ck_assert_double_eq(s21_atan(min_big_num), atan(min_big_num));
  ck_assert_double_eq(s21_atan(mzf), atan(mzf));
  ck_assert_double_eq(s21_atan(tf), atan(tf));
  ck_assert_double_eq(s21_atan(mtf), atan(mtf));
  ck_assert_double_eq(s21_atan(big_float), atan(big_float));
  ck_assert_double_eq(s21_atan(big_float), atan(big_float));
  ck_assert_double_eq(s21_atan(min_big_float), atan(min_big_float));
  ck_assert_double_eq(s21_atan(small), atan(small));
  ck_assert_double_eq(s21_atan(min_long_double), atan(min_long_double));
  ck_assert_double_eq(s21_atan(min_small), atan(min_small));
  ck_assert_double_eq(s21_atan(long_double), atan(long_double));
}
END_TEST

START_TEST(acos_test) {
  ck_assert_double_eq(s21_acos(my_inf), acos(my_inf));
  ck_assert_double_eq(s21_acos(my_min_inf), acos(my_min_inf));
  ck_assert_double_eq(s21_acos(my_nan), acos(my_nan));
  ck_assert_double_eq(s21_acos(min_nan), acos(min_nan));
  ck_assert_double_eq(s21_acos(zero), acos(zero));
  ck_assert_double_eq(s21_acos(min_zero), acos(min_zero));
  ck_assert_double_eq(s21_acos(min_small_num), acos(min_small_num));
  ck_assert_double_eq(s21_acos(small_num), acos(small_num));
  ck_assert_double_eq(s21_acos(num), acos(num));
  ck_assert_double_eq(s21_acos(min_num), acos(min_num));
  ck_assert_double_eq(s21_acos(big_num), acos(big_num));
  ck_assert_double_eq(s21_acos(min_big_num), acos(min_big_num));
  ck_assert_double_eq(s21_acos(mzf), acos(mzf));
  ck_assert_double_eq(s21_acos(tf), acos(tf));
  ck_assert_double_eq(s21_acos(mtf), acos(mtf));
  ck_assert_double_eq(s21_acos(big_float), acos(big_float));
  ck_assert_double_eq(s21_acos(big_float), acos(big_float));
  ck_assert_double_eq(s21_acos(min_big_float), acos(min_big_float));
  ck_assert_double_eq(s21_acos(small), acos(small));
  ck_assert_double_eq(s21_acos(min_long_double), acos(min_long_double));
  ck_assert_double_eq(s21_acos(min_small), acos(min_small));
  ck_assert_double_eq(s21_acos(long_double), acos(long_double));
}
END_TEST
Suite *suite_test() {
  Suite *s = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  tcase_add_test(tc1_1, abs_test);
  tcase_add_test(tc1_1, fabs_test);
  tcase_add_test(tc1_1, floor_test);
  tcase_add_test(tc1_1, ceil_test);
  tcase_add_test(tc1_1, exp_test);
  tcase_add_test(tc1_1, pow_test);
  tcase_add_test(tc1_1, sqrt_test);
  tcase_add_test(tc1_1, fmod_test);
  tcase_add_test(tc1_1, log_test);
  tcase_add_test(tc1_1, sin_test);
  tcase_add_test(tc1_1, cos_test);
  tcase_add_test(tc1_1, tan_test);
  tcase_add_test(tc1_1, asin_test);
  tcase_add_test(tc1_1, atan_test);
  tcase_add_test(tc1_1, acos_test);
  suite_add_tcase(s, tc1_1);
  return s;
}
int main(void) {
  int nf;
  Suite *s = suite_test();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
