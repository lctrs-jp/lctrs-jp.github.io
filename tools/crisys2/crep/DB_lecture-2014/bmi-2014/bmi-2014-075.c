#include <stdio.h>

int main()
{
  float w; /*体重*/
  float h; /*身長*/
  printf("weight(kg)");
  scanf("%f", &w );
  printf("height(m)");
  scanf("%f", &h );
  printf("BMI = %f", w/(h*h) );
  return 0;
}