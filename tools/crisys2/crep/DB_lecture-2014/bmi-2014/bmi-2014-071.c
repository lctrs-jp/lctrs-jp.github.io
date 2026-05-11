#include <stdio.h>

int main()
{
  float x;  /*体重の変数*/
  float y;  /*身長の変数*/

  printf("weight?(kg)\n");
  scanf("%f", &x );  /*体重を入力する*/

  printf("height?(m)\n");
  scanf("%f", &y );  /*身長を入力する*/

  printf("bmi = %f", x/(y*y) );  /*bmiの計算結果を出力*/

  return 0;
}