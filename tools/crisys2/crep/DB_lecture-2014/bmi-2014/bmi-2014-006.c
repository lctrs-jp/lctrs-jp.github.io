#include <stdio.h>

int main(void)
{
  float a,b,c;
  printf("input your height(m)\n");
  scanf("%f",&a);
  printf("input your weight(kg)\n");
  scanf("%f",&b);

  c=b/(a*a);

  printf("your BMI is %f\n",c);
  return 0;
} 
