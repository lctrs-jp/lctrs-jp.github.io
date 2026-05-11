#include <stdio.h>


int main()
{
  int weight ;
  float feet ;

  printf("weight:");
  scanf("%d", &weight);
  printf("feet:");
  scanf("%f", &feet);

  
  if( weight/(feet*feet) < 18.5 )
    printf("BMI = %f (やせ)\n", weight /(feet*feet) );
  else if( 18.5 <= weight/(feet*feet) < 25 )
    printf("BMI = %f (標準)\n", weight /(feet*feet) );
  else if( 25 <= weight/(feet*feet) < 30 )
    printf("BMI = %f (肥満)\n", weight /(feet*feet) );
  else
    printf("BMI = %f (高度肥満)\n", weight /(feet*feet) );


  return 0;
}
