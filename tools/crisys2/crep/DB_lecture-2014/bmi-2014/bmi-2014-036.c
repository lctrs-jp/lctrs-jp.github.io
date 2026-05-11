#include <stdio.h>

int main()
{
  double w; //w=weight
  double h; //h=height
  double bmi;
  
  printf("weight(kg), height(m) = ");
  scanf("%lf %lf", &w , &h );
    
  bmi=w/(h*h);
  
  printf("BMI = %lf\n",bmi);

  return 0;
}
