#include<stdio.h>

int main()
{
  float x;   //体重
  float y;   //身長
  float bmi;   //BMI値

  printf("BMIを算出するプログラムです。\n");
  printf("体重を入力してください。(kg)\n");
  scanf("%f",&x);
  printf("身長を入力してください。(m)\n");
  scanf("%f",&y);
  
  bmi = x / (y * y);

  printf("BMIは %.2f です。\n",bmi);
  printf("プログラムを終了します。\n");

  return 0;
  
}
