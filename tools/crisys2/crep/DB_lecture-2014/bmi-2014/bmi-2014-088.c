#include <stdio.h>

int main()
{
  float a,b,BMI;
  //aは体重　bは身長
  printf("体重を入力してください。");
  scanf("%f", &a );
  printf("身長を入力してください。");
  scanf("%f", &b );
  BMI=a/(b * b);
  printf("BMI=%f\n",BMI );
  return 0;
}