#include <stdio.h>
float bmi(float x,float y);  // bmiのプロトタイプ宣言

int main()

{
  printf("体重を入力してください");
  float w; /*体重(kg)*/
  printf("身長を入力してください");
  float h; /*身長(m)*/

  scanf("%f", &w);
  scanf("%f", &h); 
  
  printf("bmi=%f", bmi(w,h));
  return 0; 
}
  
  float bmi(float x,float y)  // bmiの本体
{
  return x / y / y;
}
