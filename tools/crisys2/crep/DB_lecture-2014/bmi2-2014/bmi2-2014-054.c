#include<stdio.h>

void tanyao(float bmi);

int main()
{
  int w; //体重
  float h; //身長
  float bmi; //BMI

  printf("体重を入力(kg):");
  scanf("%d",&w);
  printf("身長を入力(m):");
  scanf("%f",&h);
  bmi = w / ( h * h );
  printf("BMI=%f",bmi); //BMIを表示
  tanyao(bmi);
  return 0;
}

void tanyao(float bmi)
{
  if( bmi>=30)
    printf("  超肥満です。今すぐ手を打ちましょう。\n");
  else if( bmi<30&&bmi>=25)
    printf("  肥満です。なんとかしましょう。\n");
  else if(bmi<25&&bmi>=18.5)
    printf("  標準です。おめでとう。\n");
  else if(bmi<18.5)
    printf("  やせすぎです。気をつけましょう。\n");

}
