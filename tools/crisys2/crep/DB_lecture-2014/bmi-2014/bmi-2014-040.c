#include "stdio.h"

int main()
{
  //変数定義;
  int wei;
  double tal;

  //入力;
  printf("身長[m]を入力してください\n");
  scanf("%lf",&tal);
  printf("体重[kg]を入力してください\n");
  scanf("%d",&wei);

  //計算する;
  double bmi;
  bmi=wei/(tal*tal);

  //結果表示;
  printf("BMIは%lfです。\n",bmi);
  return 0;
}
