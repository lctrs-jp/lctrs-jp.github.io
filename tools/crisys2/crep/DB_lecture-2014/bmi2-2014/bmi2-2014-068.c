#include<stdio.h>

void judge(float,float);//判定用の関数

int main(void){
  //入力 
  float hei = 0,wei = 0;
  while(hei <= 0){
    printf("身長を入力(m):");
    scanf("%f",&hei);
  }
  while(wei <= 0){
    printf("体重を入力(kg):");
    scanf("%f",&wei);
  }
  judge(hei,wei);
  return 0;
}

void judge(float hei,float wei){
  float bmi;
  //BMI計算
  bmi = wei /(hei * hei);
  printf("あなたのBMIは%fです。\n",bmi);  
  //判定

  if(bmi <18.5)printf("あなたは「やせ」です\n");
  else if(bmi >= 18.5 && bmi <25)printf("あなたは「標準」です\n");
  else if(bmi >= 25 && bmi < 30)printf("あなたは「肥満」です\n");
  else if(bmi >= 30)printf("あなたは「高度肥満」です\n");
  else printf("エラーが発生しました。\n");
  return;
}
