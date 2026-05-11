#include <stdio.h>

int num;

int main(void)
{
  printf("2以上の整数を入力してください: ");
  scanf("%d", &num);

  while(num != 1) {
    printf("%d->", num);
    if (num % 2 == 0)
      num = num / 2;
    else if (num % 2 == 1)
      num = num * 3 +1;
  }

  printf("1");

  return 0;
}

