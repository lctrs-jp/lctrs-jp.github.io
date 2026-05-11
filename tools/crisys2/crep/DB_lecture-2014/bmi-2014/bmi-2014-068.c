#include <stdio.h>

int main()
{
  float a, b, c;
  a = 1.67;
  b = 55;
  c = b / (a * a);
  printf("身長を入力してください:");
  scanf("%f", &a);
  printf("体重を入力してください:");
  scanf("%f", &b);
  printf("あなたのBMIは %f", c);
  return 0;
}
