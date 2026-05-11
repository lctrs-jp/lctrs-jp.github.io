/*入力された体重と身長からBMIを導出し、判定するプログラム*/
#include <stdio.h>
double bmi (double x, double y); /*関数プロトタイプ*/

int main ()
{
  double w = 0, h = 0, b;

  while (1){
    printf("身長と体重を入力してください。\n");
    printf("身長(cm)："); scanf("%lf", &h);
    printf("体重(kg)："); scanf("%lf", &w);
    if (w > 0 && h > 0) break;
    printf("正の数を入力してください。");
  }

  b = bmi (w, h);
  printf("BMIは、%lfです。\n", b);

  if (b < 18.5) printf("判定は、やせです。\n");
  else if (b < 25) printf("判定は、標準です。\n");
  else if (b < 30) printf("判定は、肥満です。\n");
  else printf("判定は、高度肥満です。\n");

  return 0;
}

double bmi (double x, double y) // bmiの計算
{return x / (y * y / 10000);}
