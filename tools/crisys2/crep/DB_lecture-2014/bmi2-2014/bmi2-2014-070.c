#include <stdio.h>
float bmi(int x, float y);

int main()
{
  float h; /*身長(m)*/
  int w; /*体重(kg)*/
  printf("身長を入力してください[m]");
  scanf("%f", &h );
  printf("体重を入力してください[kg]");
  scanf("%d", &w);
  printf("%d / (%f * %f) = %f\n", w, h, h, bmi(w,h) );
  if( bmi(w,h) >= 25 ){
    if( bmi(w,h) >= 30 )
      printf("BMI = %f (高度肥満)\n", bmi(w,h) );
    else
      printf("BMI = %f (肥満)\n", bmi(w,h) );
}
  else{
    if( bmi(w,h) <= 18.5 )
      printf("BMI = %f (やせ)\n", bmi(w,h) );
    else
      printf("BMI = %f (標準)\n", bmi(w,h) );
  }
  return 0;
}

float bmi(int x, float y) 
{
  float z;
  z = x / (y * y);
  return z;
}
