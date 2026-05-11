#include <stdio.h>

float bmi(float a, float b);
int main(void)
{
  float a,b;
  printf("input your height(m)\n");
  scanf("%f",&a);
  printf("input your weight(kg)\n");
  scanf("%f",&b);
  if(a<=0 || b<=0){
    printf("input error\ninput again\n\n");
    printf("input your height(m)\n");
    scanf("%f",&a);
    printf("input your weight(kg)\n");
    scanf("%f",&b);
  }


  printf("your BMI is %f\n",bmi(a,b));
  if(bmi(a,b)<18.5)
    printf("やせ\n");
  else if(bmi(a,b)<25.0)
    printf("標準\n");
  else if(bmi(a,b)<30.0)
    printf("肥満\n");
  else
    printf("高度肥満\n");

  return 0;
} 
float bmi(float a, float b)
{
  return b/a/a;
}
