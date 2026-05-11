#include <stdio.h>

int main()
{
  int w; // 体重 kg
  float l,x; // 身長 m, BMI

  printf("体重は？:");
  scanf("%d", &w ); // 体重を入力
  printf("身長は？:");
  scanf("%f", &l ); // 身長を入力
  x = w / (l * l);

  if( x < 18.5 )
    printf("BMI = %f (やせ)\n" , x ); // BMIを出力
  else if( x < 25.0 )
    printf("BMI = %f (標準)\n" , x ); // BMIを出力
  else if( x < 30.0 )
    printf("BMI = %f (肥満)\n" , x ); // BMIを出力
  else
    printf("BMI = %f (高度肥満)\n" , x ); // BMIを出力

  return 0;
}
