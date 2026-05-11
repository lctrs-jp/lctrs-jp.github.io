#include <stdio.h>

int main()
{
  float a,b,bmi;
  printf("Imput your height = " );
    scanf("%f" , &a);
    printf("Imput your weight = ") ;
    scanf("%f" , &b) ;
    bmi=b/(a*a); //計算式
    printf("bmi = b/(a*a) %f\n",bmi);
    return 0;
}
