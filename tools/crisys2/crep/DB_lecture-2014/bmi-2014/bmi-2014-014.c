#include <stdio.h>

int main (void)
{
  double  n , w ;

  printf("身長を入力してください: ");
  scanf("%lf",  &n );
  printf("体重を入力してください: ");
  scanf("%lf",  &w );

  printf("BMIは %f", w / n / n );

  return 0;
}
