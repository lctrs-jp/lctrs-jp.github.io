#include <stdio.h>
double bmi(int w, double h);

int main()
{
  int w;
  double h;

  printf("体重を入力してください");
  scanf("%d", &w); 
  printf("身長を入力してください");
  scanf("%lf",&h);

  if(bmi(w,h) >= 30)
    printf("BMI = %lf(高度肥満)\n", bmi(w,h));
  else if(bmi(w,h) >=25)
    printf("BMI = %lf(肥満)\n", bmi(w,h));
  else if(bmi(w,h) >=18.5)
    printf("BMI = %lf(標準)\n", bmi(w,h));
  else 
    printf("BMI = %lf(やせ)\n", bmi(w,h));
  return 0;
}
double bmi(int w, double h)
{
  return w/(h*h);
}
