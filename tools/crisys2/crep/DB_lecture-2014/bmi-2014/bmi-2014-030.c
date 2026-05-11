/*体重と身長を入力しBMIを計算して出力するプログラム*/
#include <stdio.h>

int main()
{
  float weight; /*体重(kg)*/
  float height; /*身長(m)*/
  float bmi; /*BMI*/
  
  /*体重(kg)を得る*/
  printf("体重(kg)を浮動小数点数で入力してください: ");
  scanf("%f", &weight);

  /*身長(m)を得る*/
  printf("身長(m)を浮動小数点数で入力してください: ");
  scanf("%f", &height);

  /*BMIを計算*/
  bmi = weight/(height*height);

  /*答えを表示*/
  printf("BMI: %f", bmi);

  return 0;
}
