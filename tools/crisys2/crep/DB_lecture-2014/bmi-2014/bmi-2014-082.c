#include <stdio.h>

int main()
{
  int n;/*整数であることを示す*/
  float m;/*浮動小数点数*/


  printf("your weight:");/*体重を入力させる*/
  scanf("%d", &n );/*体重を入力する*/
  printf("your height:");/*身長を入力させる*/
  scanf("%f", &m );/*身長を入力する*/

  printf("BMI = %f\n", n/(m*m));/*BMIを算出する*/
  return 0;/*終わりを示す*/
}
