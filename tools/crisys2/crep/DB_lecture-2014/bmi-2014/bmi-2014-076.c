#include <stdio.h>

int main()
{
  float hei;
  int wei;

  printf("身長(m)を少数点第一位まで入力してください: ");
  scanf("%f", &hei);
  printf("体重(kg)を整数値で入力してください: ");
  scanf("%d", &wei);

  printf("BMIは %f です", wei / (hei * hei) );
  return 0;
}
  
