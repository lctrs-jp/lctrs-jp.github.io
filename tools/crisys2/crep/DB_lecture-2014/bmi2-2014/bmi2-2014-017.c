#include <stdio.h>

int hir();

int main()
{
  double b;
  
  b=hir();
   
  if(b < 18.5)
    printf("BMI = %lf (やせ)\n" , b );
  if(18.5 <= b && b < 25) 
    printf("BMI = %lf (標準)\n" , b );
  if(25 <= b && b < 30)
    printf("BMI = %lf (肥満)\n" , b );
  if(30 <= b ) 
    printf("BMI = %lf (高度肥満)\n" , b );
   
  return 0;
}

int hir()
{ 
  double h,w,b;
  
  printf("身長を入力してください[m]\n");
  scanf("%lf", &h );
  
  printf("体重を入力してください[kg]\n");
  scanf("%lf", &w );
  
  b=w/(h*h);
  
  return b;
}
