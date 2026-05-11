#include <stdio.h>

double bmi(double h, int w); //プロトタイプ宣言

int main()
{
  double h;
  int w;

  printf("身長(m) = ");
  scanf("%lf", &h);
  printf("体重(kg) = ");
  scanf("%d", &w);
 
  printf("BMI = %.2f\n", bmi(h, w));

  if(bmi(h, w) < 18.5)
    printf("やせ\n");
  if(bmi(h, w) >= 18.5 && bmi(h, w) < 25)
    printf("標準\n");
  if(bmi(h, w) >= 25 && bmi(h, w) < 30)
    printf("肥満\n");
  if(bmi(h, w) >= 30)
    printf("高度肥満\n");

  return 0;
}

double bmi(double h, int w)
{
  return (w / (h * h));
}
