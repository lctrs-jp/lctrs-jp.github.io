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

  printf("BMI = %f\n", bmi(w,h) );
  return 0;
}

float bmi(float x,float y)
{
  float z;
  z = x / (( y / 100 ) * ( y / 100 ));
  return z;
}
