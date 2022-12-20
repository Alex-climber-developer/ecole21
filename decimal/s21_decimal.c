#include "s21_decimal.h"

int main() {
  char *input = malloc(sizeof(char) * 32);

  return 0;
}
void menu(char *input) {
  int menu = 1;
  printf("[0] format input = string\n");
  printf("[1] format input = struct\n");
  scanf("%d", &menu);

  printf("Enter number, as");
  switch (menu) {
    case 0:
      printf("string{MAX 10^28}: ");
      scanf("%s", input);

      break;
    case 1:
      printf("struct{{x,x,x,x},x}: ");
      scanf("%s", input);
      unsigned int input_arr[5] = {0}, i = 0;
      char *el_arr = strtok(input, "{,}");
      while (el_arr != NULL) {
        input_arr[i++] = (unsigned int)atoi(el_arr);
        el_arr = strtok(input, "{,}");
      }
      for (int i = 0; i < 3; i++) {
        double each_el = input_arr[i];
      }

      break;

    default:
      printf("Incorrect input\n");
      break;
  }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {}
char *str_add(char *a, char *b, char *result) {
  int lena = strlen(a), lenb = strlen(b), add = 0,
      k = lena > lenb ? lena : lenb;
  k++;
  result[k--] = '\0';  // завершающий нуль-символ результата
  for (int i = lena - 1, j = lenb - 1; i >= 0 || j >= 0; i--, j--) {
    char dig1 = i < 0 ? 0 : a[i] - '0', dig2 = j < 0 ? 0 : b[j] - '0',
         dig = dig1 + dig2 + add;
    if (dig > 9) {  // если сумма разрядов >9
      dig -= 10;    // отнять 10
      add = 1;  // и сгенерировать перенос в следующий разряд
    } else
      add = 0;                // переноса нет
    result[k--] = dig + '0';  // преобразовать цифру в символ
  }
  if (!add)
    return &result[1];  // в старшем разряде результата пусто
  else {
    result[k] = add + '0';  // заполнить старший разряд результата
    return result;
  }
}
char *str_mul(char *a, char *b, char *result) {
  int lena = strlen(a), lenb = strlen(b), k = lena + lenb, s = 0;
  result[k--] = '\0';
  for (int i = 0; i <= k; i++) result[i] = 0;
  for (int i = 0; i < lena; i++) {
    for (int j = 0; j < lenb; j++) {
      int digit =
          (a[lena - i - 1] - '0') *  // получаем цифру разряда первого множителя
          (b[lenb - j - 1] - '0');
      s = i + j;  // находим текущий разряд произведения
      while (digit > 0) {
        result[k - s] += digit % 10;
        if (result[k - s] > 9) {
          result[k - s] = result[k - s] % 10;
          result[k - s - 1]++;
        }
        digit /= 10;  // корректируем предыдущую цифру разряда результата
        s++;  // переходим к предыдущему разряду результата
        if (s > k) s = k;  // не выходить за границы числа
      }
    }
  }
  // определяем первый значащий разряд результата, не равный 0
  int begin = k - s;
  while (result[begin] == 0 && begin < k) begin++;  // пропускаем ведущие нули
  for (int i = begin; i <= k; i++) result[i] += '0';
  return &result[begin];
}

// void dec_to_bin(char *data, s21_decimal value_1) {
//   //   convert input number from string to binary struct
//   char *is_floating = strchr(data, '.');
//   int ind_float_part = is_floating - data;
//   if (is_floating == NULL) {
//   } else {
//     char floating_part[1024] = {0}, c = {0};
//     int floating_part_len = 0;
//     while ((c = data[ind_float_part]) != '\0') {
//       floating_part[floating_part_len++] = c;
//     }
//     floating_part[floating_part_len] = '\0';
//   }
// }
void decimal_to_str(s21_decimal src, char *dst) {
  char *tmp = malloc(32);
  for (int i = 0; i < 3; i++) {
    char *cur_num_1 = itoa(src.bits[i], cur_num_1, 10),
         *cur_num_2 = itoa(pow((2 * INT_MAX), 2 - i), cur_num_2, 10);
    tmp = str_mul(cur_num_1, cur_num_2, tmp);
  }
}

void str_to_decimal(char *src, s21_decimal dst) {
  for (int i = 0; i < 3; i++) {
  }
}
void binary_remainder(char *remainder, char *remainder_bin) {
  //   convert remainder from string to binary struct
}
