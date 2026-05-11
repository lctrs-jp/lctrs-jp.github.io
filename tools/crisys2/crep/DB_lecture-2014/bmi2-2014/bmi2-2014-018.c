#include <stdio.h>
float bmi(float x,float y);

int main()
{
  float weight; /*体重を表す変数*/
  float height; /*身長を表す変数*/
  
  printf("あなたの体重を入力してください");
  scanf("%f", &weight );
  printf("あなたの身長を入力してください");
  scanf("%f", &height );

  if( bmi(weight,height) >= 25)
    if( bmi(weight,height) >=30)
      printf("BMI = %f (高度肥満)\n", bmi(weight,height));
    else
      printf("BMI = %f (肥満)\n", bmi(weight,height));

  else 
    if ( bmi(weight,height) >= 18.5)
      printf("BMI = %f (標準)\n", bmi(weight, height));
	 else
	   printf("BMI = %f (やせ)\n", bmi(weight,height));
    
  return 0;
} 

  float bmi(float x,float y) 
  {float z;
    z= x / (y*y);
    return z;
  }   
