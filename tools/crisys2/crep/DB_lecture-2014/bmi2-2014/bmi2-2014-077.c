#include <stdio.h>

float bmi(void);
void judge(void);
float hei;
int wei;
int main(void)
{ 
  printf("BMIは %f です。\n", bmi());
  printf("またこの値は");
  judge(); /* この部分で区分けの結果を表示 */
  printf("です。");
  return 0;
}

void judge(void) /* BMIの値による区分け */
{
  if(30.0 <= wei / (hei * hei)) /* 30以上を高度肥満に分類 */
    printf("高度肥満");
  else if(25.0 <= wei / (hei * hei)) /* 30未満25以上を肥満に分類 */
    printf("肥満");
  else if(18.5 <= wei / (hei * hei)) /* 25未満18.5以上を標準に分類 */
    printf("標準");
  else /* それ以外(18.5未満)をやせに分類 */
    printf("やせ");

  return;
}
  
float bmi(void)
{
  printf("身長(m)を少数点第一位まで入力してください: ");
  scanf("%f", &hei);
  printf("体重(kg)を整数値で入力してください: ");
  scanf("%d", &wei);

  return wei / (hei * hei); /* BMIの式の定義 */
}


