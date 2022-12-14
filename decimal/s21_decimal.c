#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int is_ok = 0;

  return is_ok;
}
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // | Вычитание | - |
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // | Умножение | * |
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // | Деление | / |
int s21_mod(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // | Остаток от деления | Mod |

void dec_to_bin(char *data, s21_decimal value_1) {
  //   convert input number from string to binary struct
  char *is_floating = strchr(data, '.');
  int ind_float_part = is_floating - data;

  if (is_floating == NULL) {
  } else {
    char floating_part[1024] = {0}, c = {0};
    int floating_part_len = 0;
    while ((c = data[ind_float_part]) != '\0') {
      floating_part[floating_part_len++] = c;
    }
    floating_part[floating_part_len] = '\0';
  }
}
void binary_remainder(char *remainder, char *remainder_bin) {
  //   convert remainder from string to binary struct
}
