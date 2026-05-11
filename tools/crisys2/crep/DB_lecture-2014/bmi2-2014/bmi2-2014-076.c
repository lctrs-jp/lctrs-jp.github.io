#include <stdio.h>
double bmi(int w, double h); /*関数bmiのプロトタイプ宣言*/
 
int main()
{
  int w;    /*体重*/
  double h; /*身長*/
  
  printf("Input your weight (kg)");  /*身長を入力*/
  scanf("%d", &w);
  printf("Input your height (m)");  /*体重を入力*/
  scanf("%lf", &h);
  
  if(w/(h*h) >= 30 )
    printf("BMI= %lf (高度肥満)\n", bmi(w,h) );
  else
    if(w/(h*h)>=25 )
      printf("BMI= %lf (肥満)\n", bmi(w,h) );
    else
      if( w/(h*h)>=18.5 )
        printf("BMI= %lf (標準)\n", bmi(w,h) );
      else
         if( 18.5>w/(h*h) )
            printf("BMI= %lf (やせ)\n", bmi(w,h) );
   return 0;
}

/*BMIを計算する関数*/
double bmi(int w, double h)
{
  return w/(h*h);
}
