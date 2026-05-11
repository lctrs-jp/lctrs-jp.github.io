#include <stdio.h>

float b (float w, float h);  //プロトタイプ宣言

float b (float w, float h){
  return h / (( w / 100) * ( w / 100 ));
}                     //BMIを計算する関数を定義
int main()
{
  float w , h  ;

  printf("身長(cm)を入力してください。\n");
  scanf("%f", &w );   //身長
  printf("体重(kg)を入力してください。\n");
  scanf("%f", &h );   //体重

  if(b(w,h) >= 30){
    printf("あなたのBMIは %f (高度肥満)です。\n", b(w,h) );
  } else if( b(w,h) >= 25 ){
    printf("あなたのBMIは %f (肥満)です。\n", b(w,h) );
  } else if( b(w,h) < 18.5){
    printf("あなたのBMIは %f (痩せ)です。\n", b(w,h) );
  } else {
    printf("あなたのBMIは %f (標準)です。\n", b(w,h) );
  };     //BMIの値で場合分け

  return 0;
}
