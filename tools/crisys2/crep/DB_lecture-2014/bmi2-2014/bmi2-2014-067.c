#include <stdio.h>

double bmi(double w, double h);//関数bmiのプロトタイプ宣言

int main()
{
  double w, h;//wは体重、hは身長を保持する変数

  printf("体重(kg)を入力してください: ");
  scanf("%lf", &w);
  printf("身長(m)を入力してください: ");
  scanf("%lf", &h);

  //以下でBMIの値と応じた判定を出力

  if( bmi(w,h) >= 25 )
    if( bmi(w,h) >= 30 )
      printf(" BMI = %lf (高度肥満)\n", bmi(w,h) );
    else
      printf(" BMI = %lf (肥満)\n", bmi(w,h) );
  else
    if( bmi(w,h) >= 18.5 )
      printf(" BMI = %lf (標準)\n", bmi(w,h) );
    else
      printf(" BMI = %lf (やせ)\n", bmi(w,h) );

  return 0;
}

//BMIを算出する関数
double bmi(double w, double h)
{
  return w / (h * h);
}
