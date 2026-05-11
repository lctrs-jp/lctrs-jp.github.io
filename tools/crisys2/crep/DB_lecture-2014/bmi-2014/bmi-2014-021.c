#include <stdio.h>


int main()
{
  int weight ;
  float feet ;

  printf("weight:");
  scanf("%d", &weight);
  printf("feet:");
  scanf("%f", &feet);

  printf("BMI=%f", weight/(feet*feet));
   



  return 0;
}
