#include <stdio.h>

void nakamichi();

int main()
{
  float a;
  float b;
  nakamichi();
  scanf("%f", &a);
  printf("身長(m)を入力してください。\n");
  scanf("%f", &b);
  printf("%f\n", a / b / b);

  if (a / b / b < 18.5)
    printf("あなたの体型は やせ です。\n");
  if (a / b / b >= 18.5 && a / b / b < 25)
    printf("あなたの体型は 標準 です。\n");
  if (a / b / b >= 25 && a / b / b < 30)
    printf("あなたの体型は 肥満 です。\n");
  if (a / b / b >= 30)
    printf("あなたの体型は 高度肥満 です。\n");

  return 0;
}

void nakamichi()
{
  printf("体重(kg)を入力してください。\n");
}
