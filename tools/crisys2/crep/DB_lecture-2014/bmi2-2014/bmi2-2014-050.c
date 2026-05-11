#include <stdio.h>
float bmi(float x, float y); /* 関数bmiのプロトタイプ宣言 */

int main()
{
  float x, y, z; /* x = 身長(cm) y = 体重(kg) z = BMI(kg/m^2) */

  printf("This program can calculate your BMI.\n");

  printf("\nAt first, input your height in centimeters.\n");
  scanf("%f", &x ); /* 身長を入力 */

  if( x > 169, x < 171 ){
    printf("Oh! You are almost as tall as Tom Cruise. \n");
  }else{}  

  printf("Next,input your weight in kilograms.\n");
  scanf("%f", &y ); /* 体重を入力 */

  printf("\nHere is the result.\nYour height = %.1f cm \n", x );
  printf("Your weight = %.1f kg \n", y ); /* 入力情報を表示 */
  printf("Your BMI = %.2f kg/m^2 \n", bmi(x,y) ); /* BMIを表示 */

  z = bmi(x,y);/* zをBMIと置く */

  if( z < 18.5 ){
    printf("(UNDER WEIGHT) \n");

      }else if( z >= 18.5, z < 25 ){
      printf("(NORMAL WEIGHT) \n");

    }else if( z >= 25, z < 30 ){
	printf("(OVER WEIGHT) \n");

  }else if( z >= 30 ){
    printf("(OBESE) \n");

  }else{
    printf("ERROR \n");
  }

  return 0;
}

/* BMIを計算する関数 */
float bmi(float x, float y)
{
  return y / ((x/100)*(x/100));
}
