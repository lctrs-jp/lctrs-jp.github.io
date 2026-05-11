#include <stdio.h>

int main()
{
  int w; // 体重 kg
  float l,x; // 身長 m, BMI

  printf("体重は？:");
  scanf("%d", &w );
  printf("身長は？:");
  scanf("%f", &l );
  x = w / (l * l);
  printf("BMI = %f\n" , x );
  return 0;
}