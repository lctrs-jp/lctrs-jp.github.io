#include <stdio.h>
float bmi(float x, float z);

float main()
{
  float h;
  float w;

  printf("身長を入力(M): ");
  scanf("%f", &h );
  printf("体重を入力(kg): ");
  scanf("%f", &w );

  if( bmi(h,w) >= 30 )
    printf("BMI = %f (高度肥満)\n", bmi(h,w) );
  if( bmi(h,w) >= 25 &bmi(h,w) < 30 )
    printf("BMI = %f (肥満)\n", bmi(h,w) );
  if( bmi(h,w) >= 18.5 &bmi(h,w) < 25 )
    printf("BMI = %f (標準)\n", bmi(h,w) );
  if( bmi(h,w) < 18.5 )
    printf("BMI = %f (やせ)\n", bmi(h,w) );

  return 0;
}

float bmi(float x, float z)
{
  float y;
  y = z / ( x * x );
  return y;
}
