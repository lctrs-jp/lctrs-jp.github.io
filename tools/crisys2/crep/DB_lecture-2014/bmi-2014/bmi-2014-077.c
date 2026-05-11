#include <stdio.h>

int main()
{
  double weight,   height;
  printf("体重を入力してください: ");
  scanf("%lf", &weight);
  printf("身長を入力してください: ");
  scanf("%lf", &height);
		  
  printf(" BMI = %lf\n" , weight / (height * height );
              
 return 0;
}
