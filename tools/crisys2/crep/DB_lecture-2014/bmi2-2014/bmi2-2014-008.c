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

  /* 肥満度を判定する */
  if (bmi<18.5)
    printf ("あなたの肥満度は「やせ」です\n");
  else if ((18.5<=bmi) && (bmi<25))
    printf ("あなたの肥満度は「標準」です\n");
  else if ((25<=bmi) && (bmi<30))
    printf ("あなたの肥満度は「肥満」です\n");
  else if (30<=bmi)
    printf("あなたの肥満度は「高度肥満」です\n");
  else

    return 0;
}
