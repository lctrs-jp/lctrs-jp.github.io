#include <stdio.h>

int main()
{
  float x; /*身長を表す*/
  int y; /*体重を表す*/
  float z;

  printf("身長: ");
  scanf("%f", &x);
  
  printf("体重: ");
  scanf("%d" , &y);
  z = y/(x * x); /*bmi*/

  printf("BMI= %f\n", z );

  return 0;
}
