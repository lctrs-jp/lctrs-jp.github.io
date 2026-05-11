/* BMIの計算をするプログラム */
#include <stdio.h>

int main(void)
{
  float weight;  /* 体重 */
  float height; /* 身長 */
  float BMI;    /* BMIの値 */
  
  /* 体重の入力 */
  printf("体重を入力してください: ");
  scanf("%f", &weight);
  
  /* 身長を入力 */
  printf("身長を入力してください: ");
  scanf("%f", &height);
  
  /* BMIの値を計算 */
  BMI = weight / (height * height);
  
  /* BMIの計算値を表示 */
  printf("BMIの値: %f\n", BMI);
  
  return 0;
}
