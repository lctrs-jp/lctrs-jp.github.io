#include <stdio.h>

int main ()
{

  int w; /* 体重(kg)を保持する変数 */
  double h; /* 身長(m)を保持する変数 */

  printf("Input your weight [kg] : ");
  scanf("%d" , &w ); /* 体重を入力 */
  printf("Input your height [m] : ");
  scanf("%lf" , &h ); /* 身長を入力 */

  if( w / (h*h) >= 30 )
    printf("BMI = %lf (高度肥満)\n" , w / (h*h) ); /* BMIを出力 */
  else if( w / (h*h) >= 25 )
    printf("BMI = %lf (肥満)\n" , w / (h*h) ); /* BMIを出力 */
  else if(w / (h*h) >=18.5 )
    printf("BMI = %lf (標準)\n" , w / (h*h) ); /* BMIを出力 */
  else
    printf("BMI = %lf (やせ)\n" , w / (h*h) ); /* BMIを出力 */

  return 0;
}
