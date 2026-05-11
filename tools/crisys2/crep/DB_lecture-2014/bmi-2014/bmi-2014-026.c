#include <stdio.h>
float bmi(float x, float z);

float main()
{
  float h;  //身長をかこう
  float w;  //体重をかこう
  scanf("%f", &h );
  scanf("%f", &w );
  printf("%f / ( %f * %f ) = %f\n", w, h, h, bmi(h,w) );
  return 0;
}

float bmi(float x, float z) 
{
  float y;
  y = z / ( x * x );
  return y;
}
