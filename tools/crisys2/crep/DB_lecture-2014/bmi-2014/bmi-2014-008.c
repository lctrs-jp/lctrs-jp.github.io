#include <stdio.h>
int main (void)
{
  float weight, height;
  float bmi;

  /* 体重と身長の入力 */
  printf ("体重(kg)を入力してください: ");
  scanf ("%f", &weight);
  printf ("身長(m)を入力してください: ");
  scanf ("%f", &height);

  /* BMI を計算する */
  bmi = weight / (height * height);
  
  /* BMIを表示する */
  printf ("BMI = %f\n", bmi);
  
  return 0;
}
