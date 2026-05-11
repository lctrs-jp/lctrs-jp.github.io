#include <stdio.h>

int main()
{
  int w=0;   /*　体重(kg)の変数　*/
  double h; /* 身長(m)の変数　*/
  
  while( w <= 0 ){
    printf("weight: ");
    scanf("%d", &w ); /* 体重 */
  }
  while(1){
    printf("height: ");
    scanf("%lf", &h ); /* 身長　*/
    if( h > 0 ) break;
  }

  if( w / (h*h) >= 25)
    if( w / (h*h) >= 30)
      printf("BMI = %lf (高度肥満)\n", w / (h*h) );
    else
      printf("BMI = %lf (肥満)\n", w / (h*h) );
  else
    if( w / (h*h) < 18.5)
      printf("BMI = %lf (やせ)\n", w / (h*h) );
    else
      printf("BMI = %lf (標準)\n", w / (h*h) );

  return 0;
}
