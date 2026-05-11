#include <stdio.h>
int templa(float bmi); 
int main()
{
  float h; /* 身長 */
  float w; /* 体重 */
  float BMI;
  printf("あなたの身長は(m)？");
  scanf("%f", &h);
  printf("あなたの体重は(kg)？");
  scanf("%f", &w);
  BMI = w / (h * h);
  printf("BMI = %f\n", BMI);
  templa(BMI);  
  return 0;
}

int templa(float bmi)
 
{    
if( bmi < 18.5 )
   printf("やせ\n");
 else if ( bmi < 25 )
   printf("標準\n");
 else if( bmi < 30 )
   printf("肥満\n");
 else if( bmi >= 30 )
   printf("高度肥満\n");
 else
   printf("不明\n");

return 0;
}
