#include <stdio.h>

int main()
{
  int w;  /* 体重(kg)を保持する変数 */
  float h; /* 身長(m)を保持する変数 */

  printf("weight:");
  scanf("%d", &w); /* 体重を入力 */
  printf("height:");
  scanf("%f", &h); /* 身長を入力 */

  if ( w/(h*h) < 18.5 )
  printf("BMI = %f (やせ)", w/(h*h)); /*BMIを出力*/
  else if ( 18.5 <= w/(h*h) < 25 )
    printf("BMI = %f (標準)", w/(h*h)); /*BMIを出力*/
    else if ( 25 <= w/(h*h) <30 )
    printf("BMI = %f (肥満)", w/(h*h)); /*BMIを出力*/   
  else 
    printf("BMI = %f (高度肥満)", w/(h*h)); /*BMIを出力*/

  return 0;
}
