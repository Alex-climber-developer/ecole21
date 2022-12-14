#include <stdio.h>   // Для printf
#include <string.h>  // Для strchr
int main(void) {
  // Массив со строкой для поиска
  char str[11] = "0123456789";
  // Код искомого символа
  int ch = '6';
  // Указатель на искомую переменную в строке,
  // по которой осуществляется поиск.
  char *ach;

  // Ищем символ ‘6’
  ach = strchr(str, ch);

  // Выводим результат на консоль
  if (ach == NULL)
    printf("Символ в строке не найден\n");
  else
    printf("Искомый символ в строке на позиции # % d\n", ach - str + 1);

  return 0;
}