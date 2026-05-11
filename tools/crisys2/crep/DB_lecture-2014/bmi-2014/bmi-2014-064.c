#include <stdio.h>
float twice(float x, float y);

int main()
{
  float c;
  float b;
  scanf("%f", &c );
  scanf("%f", &b );
  printf("BMI = %f\b", twice(c, b) );
  return 0;
} 

float twice(float x, float y)
{
  float z;
  z = x / (y * y);
  return z;
}

