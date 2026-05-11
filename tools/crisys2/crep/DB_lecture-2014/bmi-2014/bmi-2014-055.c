#include <stdio.h>

int main()
{
  double w,h;/*BMIを算出します*/
  printf("体重を入力して下さい(kg)");
    scanf("%lf", &w );
  printf("身長をお教え下さい(m)");
    scanf("%lf", &h );
  printf("BMI= %lf\n" , w /(h * h)  );
  return 0;
}
