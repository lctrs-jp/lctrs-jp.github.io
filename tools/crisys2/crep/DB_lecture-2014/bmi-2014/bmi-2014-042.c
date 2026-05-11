#include <stdio.h>

int main()
{
  double height;
  double weight;
  double BMI;
  printf("身長を入力してください。[m]\n");
  scanf("%lf", &height);
  printf("体重を入力してください。[kg]\n");
  scanf("%lf", &weight);
  BMI=weight/(height*height);
  printf("BMIは%lfです。\n",BMI);
  return 0;
}
