#include <stdio.h>

int main()
{
  int w;
  double h;

  printf("体重を入力してください[kg]:");
  scanf("%d", &w );
  printf("身長を入力してください[m]:");
  scanf("%lf", &h );

  if( w / (h*h) >= 30 )
    printf("BMI = %lf (高度肥満)\n", w / (h*h) );
  else
    if( w / (h*h) >= 25 )
      printf("BMI = %lf (肥満)\n", w / (h*h) );
    else
      if( w / (h*h) >= 18.5 )
	printf("BMI = %lf (標準)\n", w / (h*h) );
      else
	printf("BMI = %lf (やせ)\n", w / (h*h) );

  return 0;
}
