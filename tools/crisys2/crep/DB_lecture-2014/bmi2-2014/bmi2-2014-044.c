#include <stdio.h>
float bmi(int x,float z);

int main()
{
  float a;  //身長の入力
  int b;  //体重の入力 
  
  printf("身長〈m〉を入力してください。");
  scanf("%f", &a );
  printf("体重〈kg〉を入力してください。");
  scanf("%d", &b );
  printf("BMI= %f\n", bmi(b,a));
  if ( bmi(b,a)>=25){
    if( bmi(b,a)>=30)
      printf("あなたの判定は 高度肥満 です。\n");
    else
      printf("あなたの判定は 肥満 です。\n");
  }else{
    if(bmi(b,a)>=18.5)
      printf("あなたの判定は 標準 です。\n");
    else
      printf("あなたの判定は やせ です。\n");
  }
 return 0;
}

float bmi(int x,float z) 
{
  float y;
  y = x / ( z * z );
  return y;
}
