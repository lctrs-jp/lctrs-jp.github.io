#include <stdio.h>

int main()
{

  float kg , m , bmi ;

  printf("体重を入れてください(kg) :  ");
  scanf("%f" , &kg);

  printf("身長を入れてください(m) : ");
  scanf("%f" , &m);

  bmi=kg/m/m;

   printf("bmiは%fです\n " , bmi );

  

  return 0;
}
