#include<stdio.h>

float bmi(float s,float t);   //bmi関数のプロトタイプ宣言

int main()
{
  float x;   //身長
  float y;   //体重
  float z;   //bmi値

  printf("BMIを算出するプログラムです。\n");
  printf("身長を入力してください。(メートル)\n");
  scanf("%f",&x);
  printf("体重を入力してください。(キログラム)\n");
  scanf("%f",&y);
  printf("\n");

  if( x <= 0 || y <= 0 )
    {
      printf("入力が正しくされていません。\n");
      printf("プログラムを実行しなおし、値を正しく入力してください。\n");
      printf("\n");
      return 0;
   }
  
  printf("===身長：%.2f m　・　体重：%.2f kg===\n",x,y);

  z = bmi(x,y);   //関数bmiでbmiを計算
  
  printf("BMI値は %.2f です。\n",z);
  if(z < 18.5) printf("判定は やせ型 です。\n");
  if((18.5 <= z) && (z < 25)) printf("判定は 標準型 です。\n");
  if((25 <= z) && (z < 30)) printf("判定は 肥満型 です。\n");
  if(30 < z) printf("判定は 高度肥満型 です。\n");
  
  printf("プログラムを終了します。\n");

  return 0;

}
  
float bmi(float s,float t)
{
  float u;
  
  u = t / (s * s);
  
  return u;
}
