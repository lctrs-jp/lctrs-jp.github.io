/* BMIの計算をするプログラム */
#include <stdio.h>

int main(void)
{
  float weight;  /* 体重 */
  float height; /* 身長 */
  float BMI;    /* BMIの値 */

  /* 体重の入力 */
  printf("体重を入力してください(kg): ");
  scanf("%f", &weight);

  /* 身長を入力 */
  printf("身長を入力してください(m): ");
  scanf("%f", &height);
  
  /* BMIの値を計算 */
  BMI = weight / (height * height);
  
  /* BMIの値で場合分け */
  if( BMI >= 30 )
    printf("BMIの値: %f (高度肥満)\n", BMI);
  if( BMI < 30 && BMI >= 25 )
    printf("BMIの値: %f (肥満)\n", BMI);
  if( BMI < 25 && BMI >= 18.5 )
    printf("BMIの値: %f (正常)\n", BMI);
  if( BMI <= 18.5 )
    printf("BMIの値: %f (やせ)\n", BMI);

  return 0;
}
