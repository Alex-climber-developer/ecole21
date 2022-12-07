#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.c"
// #include "s21_math.h"

int main() {
  //   printf("orig: %lf  | my:  %lf\n", atan(1), s21_atan(1));
  //   for (double x = 5.123245; x < 5.2345; x += 0.01) {
  //     printf("fmod : %.6f, %.6f\n", fmod(x, x - 1.1234), s21_fmod(x, x
  //     - 1.1234));
  //   }
  //   puts("\n");
  //   for (double x = -5; x < 5; x++) {
  //     printf("exp: %lf  | exp:  %lf\n", exp(x), s21_exp(x));
  //   }
  //   puts("\n");

  for (double x = -5; x < 5; x++) {
    printf("atan: %lf  | atan:  %lf\n", atan(x), s21_atan(x));
  }
  puts("\n");

  for (double x = -5; x < 5; x++) {
    printf("asin: %lf  | asin:  %lf\n", asin(x), s21_asin(x));
  }
  puts("\n");

  return 0;
}

// START_TEST(s21_sin) {
//   //   for (double x = -5; x < 5; x++) {
//   //     printf("orig: %lf  | my:  %lf\n", cos(x), s21_cos(x));
//   //   }
//   ck_assert_double_eq(s21_sin(x), sin(x));
//   ck_assert_double_eq(s21_asin(x), asin(x));
//   ck_assert_double_eq(s21_cos(x), cos(x));
//   ck_assert_double_eq(s21_acos(x), acos(x));
//   ck_assert_double_eq(s21_tan(x), tan(x));
//   ck_assert_double_eq(s21_atan(x), atan(x));

//   ck_assert_int_eq(s21_abs(x), abs(x));
//   ck_assert_double_eq(s21_fabs(x), fabs(x));

//   ck_assert_ldouble_eq(s21_floor(x), floor(x));
//   ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
//   ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));

//   ck_assert_double_eq(s21_sqrt(x), sqrt(x));
//   ck_assert_double_eq(s21_pow(x, y), pow(x, y));

//   ck_assert_double_eq(s21_log(x), log(x));
//   ck_assert_double_eq(s21_exp(x), exp(x));
// }
// END_TEST

// // Функция создания набора тестов.
// Suite *example_suite_create(void) {
//   Suite *suite = suite_create("Example");
//   // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
//   TCase *tcase_core = tcase_create("Core of example");

//   // Добавление теста в группу тестов.
//   tcase_add_test(tcase_core, test_name);

//   // Добавление теста в тестовый набор.
//   suite_add_tcase(suite, tcase_core);

//   return suite;
// }

// int main(void) {
//   Suite *suite = example_suite_create();
//   SRunner *suite_runner = srunner_create(suite);

//   srunner_run_all(suite_runner, CK_NORMAL);
//   // Получаем количество проваленных тестов.
//   failed_count = srunner_ntests_failed(suite_runner);
//   srunner_free(suite_runner);

//   if (failed_count != 0) {
//     // Сигнализируем о том, что тестирование прошло неудачно.
//     return EXIT_FAILURE;
//   }

//   return EXIT_SUCCESS;
// }
