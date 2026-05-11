#include <stdio.h>

int main()
{
  double h,w,b;
  
  printf("身長を入力してください[m]\n");
  scanf("%lf", &h );

  printf("体重を入力してください[kg]\n");
  scanf("%lf", &w );

  b=w/(h*h);
  printf("BMI= %lf\n" , b );
  
  return 0;
}
