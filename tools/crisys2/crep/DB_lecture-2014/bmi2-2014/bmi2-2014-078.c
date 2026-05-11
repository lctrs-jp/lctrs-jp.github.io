#include <stdio.h>

void kadn(void);

int main(void)
{

  int weight; /* 体重(kg) */
  double height; /* 身長 */
  kadn();
  printf("体重を入力してください: "); 
  scanf("%d", &weight ); /* 体重を入力 */
  printf("身長を入力してください: ");
  scanf("%lf", &height ); /* 身長を入力 */ 

  if( weight / (height*height) >= 30 )
    printf("BMI = %lf (高度肥満)\n", weight / (height*height) ); /* BMIを出力 */ 
  if( weight / (height*height) < 30 && weight / (height*height) >= 25 )
    printf("BMI = %lf (肥満)\n", weight / (height*height) ); /* BMIを出力 */
  if( weight / (height*height) < 25 && weight / (height*height) >= 18.5 )
    printf("BMI = %lf (標準)\n", weight / (height*height) ); /* BMIを出力 */
  if( weight / (height*height) < 18.5 )
    printf("BMI = %lf (やせ)\n", weight / (height*height) ); /* BMIを出力 */

  return 0;
}

void kadn(void)
{
  printf("あなたの");
}
