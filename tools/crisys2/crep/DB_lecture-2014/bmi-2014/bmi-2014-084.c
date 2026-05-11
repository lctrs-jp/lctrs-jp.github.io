#include <stdio.h>
int main(void)
{
  float hei, wei; //変数の宣言

  printf("体重(kg)を入力してください:");
  scanf("%f", &wei); //体重を入力
  printf("身長(cm)を入力してください:");
  scanf("%f", &hei); //身長を入力

  printf("BMIは %f です。\n", wei / (hei / 100 * hei / 100));
  /* BMI = 体重(kg) / (身長(cm) * 身長(cm)) */

  return 0;
}
