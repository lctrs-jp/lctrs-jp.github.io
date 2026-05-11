#include <stdio.h>
int height();

int main()
{
  float a,b,BMI;
  //aは体重　bは身長
  printf("体重(kg)を入力してください。");
  scanf("%f", &a );
  height();
  scanf("%f", &b );
  BMI= a/(b * b);
  if( a/(b * b) >=30 )
	  printf("BMI = %f （高度肥満）\n", BMI);
  else
	  if( a/(b * b) >=25 )
	  printf("BMI = %f （肥満）\n", BMI);
	  else 
		  if( a/(b * b) >=18.5 )
	      printf("BMI = %f （標準）\n", BMI);
		  else
	      printf("BMI = %f （やせ）\n", BMI);	  
        
  return 0;
}

int height()
{
	printf("身長(m)を入力してください。");
	return 0;
}
