#include <stdio.h>

int main()
{
  float x, y; /* x = 身長(cm) y = 体重(kg) */

  printf("This program can calculate your BMI.\n");

  printf("\nAt first, input your height in centimeters.\n");
  scanf("%f", &x ); /* 身長を入力 */

  printf("Next,input your weight in kilograms.\n");
  scanf("%f", &y ); /* 体重を入力 */

  printf("\nHere is the result.\nYour height = %.1f cm \n", x );
  printf("Your weight = %.1f kg \n", y ); /* 入力情報を表示 */
  printf("Your BMI = %.2f kg/m^2 \n", y/((x/100)*(x/100)) ); /* BMIを表示 */

  return 0;
}
