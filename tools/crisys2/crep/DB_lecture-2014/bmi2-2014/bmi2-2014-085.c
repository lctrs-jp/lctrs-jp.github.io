#include <stdio.h>
double bmi(double wei, double hei); /* 関数bmiのプロトタイプ */

int main(void)
{
  double hei, wei; /* 変数の宣言 */

  printf("体重(kg)を入力してください:");
  scanf("%lf", &wei); /* 体重を入力 */
 
  printf("身長(m)を入力してください:");
  scanf("%lf", &hei); /*身長を入力 */
  
  printf("BMIは %lf です。\n", bmi(wei,hei)); /* BMIの出力 */

  /* BMIによる肥満度判定 */
  if (bmi(wei,hei) < 30)  
    if (bmi(wei,hei) <25)
      if (bmi(wei,hei) < 18.5)
	printf("あなたはやせです。\n"); /* 18.5未満はやせ */
      else
	printf("あなたは標準です。\n"); /* 18.5～25未満は標準 */
    else
      printf("あなたは肥満です。\n"); /* 25～30未満は肥満 */
  else
    printf("あなたは高度肥満です。\n"); /* 30以上は高度肥満 */
	return 0; 
}

/* BMIの計算 */
double bmi(double wei, double hei)
{
return wei / ( hei * hei );
}
