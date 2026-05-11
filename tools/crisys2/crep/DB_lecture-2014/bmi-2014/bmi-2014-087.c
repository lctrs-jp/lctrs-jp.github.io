#include <stdio.h>

int main()
{
  double h,w,x;

  printf("体重");
    scanf("%lf", &w );
    printf("身長");
    scanf("%lf", &h );
    
    x=w/(h*h);
    printf("x=%lf\n", x );
    return 0;
}
