#include <stdio.h>
float bmi(float x,float y);

int main()
{
  float w;
  float h;

  printf("体重を入力(kg) \n");
  scanf("%f", &w );

  printf("身長を入力(cm) \n");
  scanf("%f", &h );

  if( bmi(w,h) >= 30 )
    printf("BMI = %f (高度肥満)\n", bmi(w,h) );
  else
    if( bmi(w,h) >= 25 )
      printf("BMI = %f (肥満)\n", bmi(w,h) );
    else
      if( bmi(w,h) >= 18.5)
	printf("BMI = %f (標準)\n", bmi(w,h) );
      else
	printf("BMI = %f (やせ)\n", bmi(w,h) );
  return 0;
}

float bmi(float x,float y)
{
  float z;
  z = x / (( y / 100 ) * ( y / 100 ));
  return z;
}
