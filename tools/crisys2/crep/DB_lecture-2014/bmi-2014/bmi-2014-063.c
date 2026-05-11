#include <stdio.h>

int main()
{
  float w , h , bmi;
  printf("あなたの体重を入力してください。\n");
  scanf("%f", &w );             /* 体重を代入 */
  printf("あなたの身長を入力してください。\n");
  scanf("%f", &h );             /* 身長を代入 */ 
  bmi = w * 10000 / ( h * h );  /* BMIを計算 */
  printf("あなたのBMIは %f です。\n", bmi );
  return 0;
}
    
