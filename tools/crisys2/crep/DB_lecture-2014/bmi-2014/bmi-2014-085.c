#include <stdio.h>

int main()
{
  int x;/*体重を表す変数*/
  float y;/*身長を表す変数*/

  printf("体重(kg)は？：");
  scanf("%d",&x);/*体重を入力*/
  printf("身長(m)は？:");
  scanf("%f" ,&y);/*身長を入力*/

  printf("BMIは %f\n", x/(y*y));/*BMIを計算、表示*/

  return 0;
}
