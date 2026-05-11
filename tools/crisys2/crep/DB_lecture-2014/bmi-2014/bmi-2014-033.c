#include <stdio.h>

int main()
{
   double s, t;
  
   printf("1.身長（ｍ）\n"); 
   printf("2.体重（kg）\n"); /*入力する数値を示す*/

   scanf("%lf", &s );
   scanf("%lf", &t );
   printf("BMI値:%lf", t/(s*s));
   return 0;
}
