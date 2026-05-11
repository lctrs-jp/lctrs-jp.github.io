#include <stdio.h>
float calbmi(float h,float w);
int main()
{
  //身長と体重からbmiを求めるプログラム
  float hig, wei, bmi;

  //身長体重の入力
  while(1){
    printf("身長(m)と体重(kg)を入力してください\n");
    scanf("%f %f",&hig,&wei);
    if(hig<0 || wei<0){
      printf("入力が不正です\n");
    }
    else
      break;
    }

  //BMIを計算して返す
  bmi = calbmi(hig,wei);

  printf("あなたのBMIは%fです\n",bmi);

  //肥満度の判定
  if(bmi<18.5){
    printf("あなたはやせです\n");
  }
  else if(bmi<25){
    printf("あなたは標準です\n");
  }
  else if(bmi<30){
    printf("あなたは肥満です\n");
  }
  else{
    printf("あなたは高度肥満です\n");
  }
  return 0;
}


float calbmi(float h,float w)
{
  return w/(h*h);
}
