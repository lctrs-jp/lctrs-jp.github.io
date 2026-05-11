#include <stdio.h>

float calcBMI(void);

int main(void)
{
  float bmi = 0;

  // BMIを計算
  bmi = calcBMI();

  // 計算結果を表示
  printf("BMI = %.2f\n", bmi);

  return 0;
};

float calcBMI(void)
{
  float height = 0;
  float weight = 0;

  // 身長を入力
  printf("input your height (m)\n");
  printf(">> ");
  scanf("%f", &height);

  // 体重を入力
  printf("input your weight (kg)\n");
  printf(">> ");
  scanf("%f", &weight);

  // BMIを計算
  return (weight/(height*height));
};
