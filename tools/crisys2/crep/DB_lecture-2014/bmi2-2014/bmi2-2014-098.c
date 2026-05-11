#include<stdio.h>
double bmi(int w,double h);

int main()
{
  int w;
  double h;

  printf("Input your weight");
  scanf("%d",&w);
  printf("Input your height");
  scanf("%lf",&h);
  printf("BMI=%lf\n",bmi(w,h));
  
  if(w/(h*h)<18.5)
    printf("BMI=%lf(やせ)\n",w/(h*h) );
  else if(w/(h*h)<25)
      printf("BMI=%lf(標準)\n",w/(h*h) );
  else if(w/(h*h)<30)
    printf("BMI=%lf(肥満)\n",w/(h*h) );
  else 
    printf("BMI=%lf(高度肥満)\n",w/(h*h) );

  return 0;
}

double bmi(int w,double h)
{
  return w/(h*h);
}
