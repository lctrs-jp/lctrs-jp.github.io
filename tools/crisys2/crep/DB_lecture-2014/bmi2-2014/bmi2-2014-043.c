#include <stdio.h>
double bmi(double w, double h); /* 関数bmiのプロトタイプ宣言 */

int main()
{
  double w;    /* 体重(kg)を保持する変数 */
  double h; /* 身長(m)を保持する変数 */
  printf("体重を入力してください[kg]: ");
  scanf("%lf", &w ); /* 体重を入力 */
  printf("身長を入力してください[m]: ");
  scanf("%lf", &h ); /* 身長を入力 */
  if( w / (h*h) >= 30 )
    printf("BMIは%lfです。 (高度肥満)\n", w / (h*h) ); /* BMIを出力 */
  else if( w / (h*h) >= 25 && w / (h*h) < 30 )
    printf("BMIは%lfです。 (肥満)\n", w / (h*h) ); /* BMIを出力 */
  else if( w / (h*h) >= 18.5 && w / (h*h) < 25 )
    printf("BMIは%lfです。 (標準)\n", w / (h*h) ); /* BMIを出力 */
  else
    printf("BMIは%lfです。 (やせ)\n", w / (h*h) ); /* BMIを出力 */  
return 0;
}

/* BMIを計算する関数 */
double bmi(double w, double h)
{
  return w / (h*h);
}

