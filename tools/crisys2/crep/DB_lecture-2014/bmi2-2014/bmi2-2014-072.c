#include <stdio.h>
int func1();

int main()
{
  float x, y;

  printf("あなたの体重(kg)は?");
  scanf("%f", &x);
  func1();
  scanf("%f", &y);

  if(x/(y*y) >=30)
    printf("BMI = %f (高度肥満)\n", x/(y*y) );
  else
    if(x/(y*y) >=25)
      printf("BMI = %f (肥満)\n", x/(y*y) );
    else
      if(x/(y*y) >= 18.5)
	printf("BMI = %f (標準)\n", x/(y*y) );
      else
	printf("BMI = %f (やせ)\n", x/(y*y) );

  return 0;
}

int func1()
{
  printf("あなたの身長(m)は?");

  return 0;
}
