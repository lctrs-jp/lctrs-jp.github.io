#include<stdio.h>

/*BMIを計算する関数*/

float bmi(int x,float y)
{
  return x/(y*y);
}

int main(void)
{
  int x;/*体重を表す変数*/
  float y;/*身長を表す変数*/

  printf("体重(kg)は？：");
  scanf("%d",&x);/*体重を入力*/
  printf("身長(m)は？:");
  scanf("%f",&y);/*身長を入力*/

  if(bmi(x,y)>=25&&bmi(x,y)<30)
    printf("BMI=%f(肥満)\n", bmi(x,y) );/*BMIを出力*/
  else if(bmi(x,y)>=30)
    printf("BMI=%f(高度肥満)\n",bmi(x,y));/*BMIを出力*/
  else if(bmi(x,y)>=18.5&&bmi(x,y)<25)
    printf("BMI=%f(標準)\n",bmi(x,y));/*BMIを出力*/
  else
    printf("BMI=%f(痩せ)\n",bmi(x,y));/*BMIを出力*/

  return 0;


}


