/*入力された体重と身長からBMIを導出するプログラム*/
#include <stdio.h>
double bmi (double x, double y); /*関数プロトタイプ*/

int main ()
{
  double w, h;

  printf("身長と体重を入力してください。\n");
  printf("身長(cm)："); scanf("%lf", &h);
  printf("体重(kg)："); scanf("%lf", &w);
  
  printf("BMIは、%lfです。\n", bmi(w, h));
  return 0;
}

double bmi (double x, double y) // bmiの計算
{
  double b;
  b = x / (y * y / 10000);
  return b;
}
