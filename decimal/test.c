
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main() {
// float f = 111111111111.5;
// unsigned int bits = *((unsigned int *)&f);
// printf("%d\n", bits);

// for (unsigned int mask = 0x80000000; mask; mask >>= 1) {
//   printf("%d", !!(bits & mask));
// }

// // 2147483647
// unsigned int a = 1000000000;
// unsigned int b = 1000000000;
// char str[17];
// itoa(a * b, str, 10);
// printf(str);

// }

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

int main() {
  // описываем массивы символов для хранения введенных чисел
  char a[1000] = {0};
  char b[1000] = {0};
  char *c = malloc(sizeof(char) * 32);
  // Вводим два числа
  printf("a = ");
  scanf("%s", a);

  printf("b = ");
  scanf("%s", b);
  // Выводим результат произведения
  // strcpy(c, str_add(a, b, c));
  char *x = str_add(a, b, c);
  printf("a+b = %s\nx*1000 = %s\n", x, str_mul(x, "1000", c));
  printf("a+b = %s\nx*1000 = %s\n", str_add(a, b, c),
         str_mul(str_add(a, b, c), "1000", c));
  free(c);
  return 0;
}