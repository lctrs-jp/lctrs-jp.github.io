#include <stdio.h>
double bmi(float weight, float height); /*関数bmiのプロトタイプ宣言 */

int main()
{
  float weight; /* 自分の体重 */
  float height; /* 自分の身長 */
  
    /* 身長と体重を得る */
    printf(" 体重を入力してください(kg): ");
    scanf("%f", &weight);
    printf(" 身長を入力してください(m): ");
    scanf("%f", &height);
    

    /* BMIを計算する関数 */
    double bmi(float weight, float height) 
    {
     return weight /(height * height);
    }

    if ( bmi(weight,height) <18.5 )
      printf("BMI = %f (やせ)\n", bmi(weight,height));/*BMIを出力*/   
    else if ( bmi(weight,height) >= 18.5 , bmi(weight,height) < 25 )
      printf("BMI = %f (標準)\n", bmi(weight,height));
    else if ( bmi(weight,height) >= 25, bmi(weight,height) < 30 ) 
	  printf ("BMI = %f (肥満)\n", bmi(weight,height));
    else if ( bmi(weight,height) > 30 )
      printf("BMI = %f (高度肥満)\n", bmi(weight,height));


    return 0;
} 
