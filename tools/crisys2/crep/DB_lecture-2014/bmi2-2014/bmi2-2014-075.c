#include <stdio.h>
float bmi(float x,float y);  // bmiのプロトタイプ宣言

int main()

{
  printf("体重(kg)を入力してください\n");
  float w; /*体重(kg)*/
  scanf("%f", &w);
  printf("身長(m)を入力してください");
  float h; /*身長(m)*/
  scanf("%f", &h);

  printf("bmi=%f", bmi(w,h));

  if (bmi(w,h) < 18.5)
    printf("あなたは痩せすぎです");
  else
  if (18.5 <= bmi(w,h) < 25)
    printf("あなたは普通です");
  else
  if (25 <= bmi(w,h) < 30)
    printf("あなたは肥満です");
  else
  if (30 <= bmi(w,h))
    printf("あなたはかなり肥満です");

  return 0;
}

float bmi(float x,float y)  // bmiの本体
{
  return x / y / y;
}
