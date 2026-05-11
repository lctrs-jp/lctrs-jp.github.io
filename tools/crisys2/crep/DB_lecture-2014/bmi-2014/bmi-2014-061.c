#include <stdio.h>


int main()
{
  double w,h,BMI;
  printf("体重");
  scanf("%lf", &w );
  printf("身長");
  scanf("%lf", &h );
  BMI = w/(h*h);
  printf("BMI = %lf", BMI );
  return 0;