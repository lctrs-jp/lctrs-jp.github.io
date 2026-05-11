#include<stdio.h>

int main()
{
  double l;
  double w;
  double bmi;
  
  printf(" 身長を入力してください(m):");
  scanf("%lf", &l );
  printf("体重を入力してください(kg):");
  scanf("%lf", &w);
  bmi = w / ( l * l );
  printf("bmi = %lf\n", bmi);

  return 0;
}
