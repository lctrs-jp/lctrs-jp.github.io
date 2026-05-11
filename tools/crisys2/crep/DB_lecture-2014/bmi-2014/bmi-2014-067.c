#include<stdio.h>
int bmi(int);
int main(){
    
  float hei,wei,bmi;
  printf("身長を入力してください(m)");
  scanf("%f",&hei);                        /*身長を入力させる*/
  printf("体重を入力してください(kg)");
  scanf("%f",&wei);                       /*体重を入力させる*/
  bmi = wei / (hei * hei);                /*BMIの計算*/
  printf("あなたのbmiは:%fです\n",bmi);     /*出力*/
 return 0;
}
