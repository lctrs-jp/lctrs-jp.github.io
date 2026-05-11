#include <stdio.h>

float user(int w,float h);/*関数userのプロトタイプ宣言*/



int main()
{
  int w; /*体重(kg)を保有する変数*/
  float h; /*身長(m)を保有する変数*/

  printf("体重(kg)を入力してください:" );
  scanf("%d", &w );

  printf("身長(m)を入力してください:");
  scanf("%f", &h );

  /*BMIとその数値に基づいた肥満度の判定*/

  if(w /(h * h) >=30)
    printf("BMIは %f　です。（高度肥満）", user(w,h));
  
  else
    if(30>w /(h * h) && w /(h * h)>=25)
    printf("BMIは %f　です。(肥満）", user(w,h));
  
  else
    if(25>w /(h * h) && w /(h * h)>=18.5)
    printf("BMIは　%f です。(標準)" , user(w,h));
  
  else
    printf("BMIは　%f です。(やせ)" , user(w,h));  



  return 0;
}

float user(int w,float h) /*関数userの本体*/
{
  return w/(h * h);
}
