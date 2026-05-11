#include <stdio.h>
float bmi(int x,float z);

int main()
{
  float a;  //身長
  int b;  //体重 

  scanf("%f", &a );
  scanf("%d", &b );
  printf("%d /( %f * %f) = %f\n", b, a, a, bmi(b,a) );
  return 0;
}

float bmi(int x,float z) 
{
  float y;
  y = x / ( z * z );
  return y;
}
