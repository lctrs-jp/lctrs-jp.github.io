#include <stdio.h>
float bmi(float y, int x);

int main()
{
  float h;  /* 身長(h) */
  int m;  /* 体重(m) */
  scanf("%f", &h );
  scanf("%d", &m );
    printf("%d/(%f*%f) = %f\n", m, h, h, bmi(h,m) );
  return 0;
}

float bmi(float y, int x)
{
  float z;
  z = x/(y*y); /* bmiの計算 */
  return z;
}
