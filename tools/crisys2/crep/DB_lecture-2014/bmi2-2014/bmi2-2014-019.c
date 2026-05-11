// BMIを計算して出力するプログラム (2014.10.16)

#include <stdio.h>

double bmi(double w, double h);  // bmiのプロトタイプ

int main()
{
  double w, h;  // w: 体重(kg)を表す変数、h: 身長(cm)を表す変数

  printf("体重(kg)を入力してください: ");
  scanf("%lf", &w);  // 体重(kg)を入力
  printf("身長(cm)を入力してください: ");
  scanf("%lf", &h);  // 身長(cm)を入力

  double b = bmi(w, h);

  if(b < 18.5)
    printf("BMIは %.2lf (やせ)\n", b);  // 小数点以下二桁まで表示

  else if(18.5 <= b && b < 25)
    printf("BMIは %.2lf (標準)\n", b);  //小数点以下二桁まで表示

  else if(25 <= b && b < 30)
    printf("BMIは %.2lf (肥満)\n", b);  //小数点以下二桁まで表示

  else
    printf("BMIは %.2lf (高度肥満)\n", b);  //小数点以下二桁まで表示

  return 0;
}

//BMIの計算式
double bmi(double w, double h)
{
  double hm = h / 100;

  return w / (hm * hm);
}
