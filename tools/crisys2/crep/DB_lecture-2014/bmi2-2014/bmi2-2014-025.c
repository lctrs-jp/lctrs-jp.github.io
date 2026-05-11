
/* BMIの計算 */
#include <stdio.h>

int BMI(int x, float y); /* 関数BMIのプロトタイプ宣言*/

int main()
{
 int w; /* 体重を格納する変数 */
 float h; /* 身長を格納する変数 */

 /* 体重の入力*/
 while(1){
   printf("体重を入力してください(kg)");
   scanf("%d", &w);

   if (w<=0)
     printf("正の数を入力してください\n");
   else
     break;
 }

 /* 身長の入力*/
 while(1){
   printf("身長を入力してください(m)");
   scanf("%f", &h);

   if (h<=0)
     printf("正の数を入力してください\n");
   else
     break;
 }

 BMI(w,h);

 return 0;
}

 /* BMIの計算と表示を行う関数 */
int BMI(int x, float y)
{
  float bmi;

  bmi=x/(y*y);

  printf("あなたのBMIは %f で、",bmi);

  /*BMIの判定*/
  if(bmi<18.5){
    printf("やせ型です。\n");
  }
  else if(bmi<25){
    printf("標準です。\n");
  }
  else if(bmi<30){
    printf("肥満です。\n");
  }
  else{
    printf("高度肥満です。\n");
  }

  return 0;
}

