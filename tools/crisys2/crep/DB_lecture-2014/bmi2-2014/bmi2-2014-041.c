#include "stdio.h"

int bmijudge(double bmij);

int main(){
  //変数定義;
  int wei;
  double tal;

  //入力;
  while(1){
    printf("身長[m]を入力してください\n");
    scanf("%lf",&tal);
    if (tal<0) {
      printf("数値が不適切です。\n");
      continue;
    }else{
      break;
    }
  }
  while(1){
    printf("体重[kg]を入力してください\n");
    scanf("%d",&wei);
    if (wei<0) {
      printf("数値が不適切です。\n");
      continue;
    }else{
      break;
    }
  }
  //計算する;
  double bmi;
  bmi=wei/(tal*tal);

  //結果表示;
  printf("BMIは%lfです。\n",bmi);

  switch(bmijudge(bmi)) {
  case 1:
    printf("あなたの肥満度は やせ です。\n");
    break;
  case 2:
    printf("あなたの肥満度は 標準 です。\n");
    break;
  case 3:
    printf("あなたの肥満度は 肥満 です。\n");
    break;
  case 4:
    printf("あなたの肥満度は 高度肥満 です。\n");
    break;
  default:
    printf("肥満度の評価に失敗しました\n");
    break;
  }
  return 0;
}
//肥満度判定用関数
int bmijudge(double bmij){//本当は文字列型変数を返したかった
  if (18.5>bmij) { return 1; }
  if (18.5<=bmij && bmij<25.0) { return 2; }
  if (25.0<=bmij && bmij<30.0) { return 3; }
  if (30.0<=bmij) { return 4; }
  return 0;
}
