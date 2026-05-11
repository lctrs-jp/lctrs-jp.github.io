#include <stdio.h>
/* 作成：　作成日：10/20*/
float cal(int x,float y);
int main()
{
  int  Wt; /*体重を示す変数*/
  float Ht , Bm; /*Htは身長、BmはBMIを示す変数*/
  printf("体重は何㎏？\n");
  scanf("%d" , &Wt );
  printf("身長は何m？\n");
  scanf("%f" , &Ht );
  Bm = cal(Wt,Ht);
  if(Bm >= 30){  /*BMIにより肥満度を判別*/
    printf("あなたのBMIは%fで肥満度は高度肥満です\n", Bm );
  }
  if(Bm >= 25 && Bm < 30){
    printf("あなたのBMIは%fで肥満度は肥満です\n", Bm );
  }   
  if(Bm >= 18.5 && Bm < 25){
    printf("あなたのBMIは%fで肥満度は標準です\n", Bm );
  }   
  if(Bm < 18.5){
    printf("あなたのBMIは%fで肥満度はやせです\n", Bm );
  }  

  return 0;
}

float cal(int x,float y) /*BMI計算関数 */
{   
  float z;
  z = x/(y*y);
  return z;
}
