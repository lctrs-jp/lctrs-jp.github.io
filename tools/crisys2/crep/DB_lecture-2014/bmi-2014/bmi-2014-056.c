#include <stdio.h>

int main(void)
{
  double h,w,x ;
  printf("身長を入力してください（m）");
  scanf("%lf", &h );
  printf("体重を入力してください（kg）");
  scanf("%lf", &w );
  x=w/(h*h);
  printf("bmi");
  printf("%lf\n",x);
  return 0;
}
