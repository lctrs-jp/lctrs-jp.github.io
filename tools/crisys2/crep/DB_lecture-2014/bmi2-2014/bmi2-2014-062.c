#include <stdio.h>
double bmi(int w, double h);


int main()
{
  int w;
  double h;
  printf("Input your weight: ");
  scanf("%d", &w );
  printf("Input your height: ");
  scanf("%lf", &h );
  printf("BMI = %lf\n", bmi(w,h) );
  if( bmi(w,h) >= 25 )
    if( bmi(w,h) >= 30 )
       printf("あなたは高度肥満です");
    else 
       printf("あなたは肥満です");
  else
    if( bmi(w,h) < 18.5)
       printf("あなたはやせです");
    else
       printf("あなたは標準です");
  return 0;
}


double bmi(int w, double h)
{
  return w / (h*h);
}
