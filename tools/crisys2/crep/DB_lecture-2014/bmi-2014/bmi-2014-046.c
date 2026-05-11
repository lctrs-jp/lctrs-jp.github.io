#include <stdio.h>

int main()
{
   double x;
   double y;
   double bmi;
 printf("身長を入力してください(cm)\n");
 scanf("%lf",&x );
 printf("体重を入力してください(kg)\n");
 scanf("%lf",&y );
 printf("あなたのBMIは %.1f\n", bmi=y*10000/(x*x));
 return 0;
}
