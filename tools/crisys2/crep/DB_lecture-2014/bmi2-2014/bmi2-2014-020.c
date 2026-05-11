#include <stdio.h>
float bmi(); /*プロトタイプ宣言*/

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

  if( z >= 30 )
    printf("BMI= %f (高度肥満) \n", z );
  
 else if( z < 30 && z >= 25 )
    printf("BMI= %f (肥満) \n", z );

 else if( z < 25 && z >= 18.5 )
    printf("BMI= %f (標準) \n", z );
 
 else if( z < 18.5 )
    printf("BMI= %f (やせ) \n", z );

 return 0;
}

float bmi( z )

{
  return z;
}
