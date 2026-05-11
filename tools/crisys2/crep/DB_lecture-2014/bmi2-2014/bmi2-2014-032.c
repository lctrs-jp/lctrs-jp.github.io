/*体重と身長を入力しBMIを計算して判定し、出力するプログラム*/
#include <stdio.h>

void func1(void); /*プロトタイプ*/

int main()
{
  float weight; /*体重(kg)*/
  float height; /*身長(m)*/
  float bmi; /*BMI*/
  
  /*体重(kg)を得る*/
  func1();
  scanf("%f", &weight);

  /*身長(m)を得る*/
  printf("身長(m)を浮動小数点数で入力してください: ");
  scanf("%f", &height);bmi

  /*BMIを計算*/
  bmi = weight/(height*height);

  /*答えを表示*/
  printf("BMI: %f\n", bmi);

  if( bmi < 18.5 ) /*判定*/
    printf("(やせ)");
  if( bmi >= 18.5 && bmi < 25 )
    printf("(標準)");
  if( bmi >=25 && bmi < 30 )
    printf("(肥満)");
  if( bmi >= 30 )
    printf("(高度肥満)");

  return 0;
}

void func1(void)
{
  printf("体重(kg)を浮動小数点数で入力してください: ");
}
