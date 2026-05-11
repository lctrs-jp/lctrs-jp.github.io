#include <stdio.h>

int main()
{
  double height;
  int weight;
  
  printf("身長(m) = ");
  scanf("%lf", &height);
  printf("体重(kg) = ");
  scanf("%d", &weight);

  printf("BMI = %.2f\n", (double)weight / (height * height));
  // 2014/10/09 ***** 作
  return 0;
}
