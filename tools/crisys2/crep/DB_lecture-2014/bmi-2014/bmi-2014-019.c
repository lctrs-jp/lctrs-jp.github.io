#include <stdio.h>

int main()
{
  float n ,l ;
    
  printf("あなたの体重は？(kg)\n");
  scanf("%f", &n );
  printf("あなたの身長は？(m)\n");
  scanf("%f", &l );
 
  printf("BMI = %1f\n", n/(l*l) );
  
  return 0;
}
