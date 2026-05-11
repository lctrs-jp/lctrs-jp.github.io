#include <stdio.h>
float bmi(int x, float y);

int main()
{
  float h; /*身長(m)*/
  int w; /*体重(kg)*/
  scanf("%f", &h );
  scanf("%d", &w);
  printf("%d / (%f * %f) = %f\n", w, h, h, bmi(w,h) );
  return 0;
}

float bmi(int x, float y) 
{
  float z;
  z = x / (y * y);
  return z;
}
