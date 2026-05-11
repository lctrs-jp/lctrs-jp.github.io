#include <stdio.h>

int main()
{
  float a;
  float b;
  printf("体重(kg)を入力してください。\n");
  scanf("%f", &a );
  printf("身長(m)を入力してください。\n");
  scanf("%f", &b );
  printf("BMIは,%f\n", a / b / b);
  return 0;
}
