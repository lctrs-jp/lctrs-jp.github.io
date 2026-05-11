#include<stdio.h>

int main()
{
  double h, w;    /*身長h 体重w*/

  printf("身長(m):");
  scanf("%lf", &h);

  printf("体重(kg):");
  scanf("%lf", &w);

  double bmi;
  bmi = w/(h*h);

  printf("BMI値:%lf\n", bmi);

  return 0;
}
