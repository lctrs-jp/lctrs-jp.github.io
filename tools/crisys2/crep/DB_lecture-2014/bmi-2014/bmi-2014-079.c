#include <stdio.h>

int main()
{
  int w;/* wは体重（整数）（単位はkg） */
  float h;/* hは身長（少数）（単位はm）*/
  /*体重、身長の順に数値を入力するとBMIが計算される*/
  scanf("%d", &w );
  scanf("%f", &h );
  printf("BMI = %f\n", w / ( h * h ) );
  return 0;
}
