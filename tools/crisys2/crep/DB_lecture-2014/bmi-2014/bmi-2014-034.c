#include <stdio.h>/*BMI計算プログラム*/

int main()
{
  double height, weight;
  float BMI;

  /*数値入力*/
  printf("身長を入力[cm]\n");
  scanf("%lf",&height);

  printf("体重を入力[kg]\n");
  scanf("%lf",&weight);

  /*計算結果:*/
  BMI = 10000*weight/(height*height);
  printf("あなたのBMI:%f\n",BMI);

  return 0;
}