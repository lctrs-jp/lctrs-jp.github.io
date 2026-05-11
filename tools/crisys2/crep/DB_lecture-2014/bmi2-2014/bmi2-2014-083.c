#include <stdio.h>

int main()
{
  int n;/*整数であることを示す*/
  float m;/*浮動小数点数*/


  printf("your weight(kg):");/*体重を入力させる*/
  scanf("%d", &n );/*体重を入力する*/
  printf("your height(m):");/*身長を入力させる*/
  scanf("%f", &m );/*身長を入力する*/

  /*以下はBMIの計算のやり方と判断の目安*/
 
  if ( n/(m*m) < 18.5)
    printf("BMI = %lf (痩せ)\n", n/(m*m) );
  if ( 18.5<= n/(m+m) && n/(m*m) < 25 )
    printf("BMI = %lf (標準)\n", n/(m*m) );
  if ( 25<= n/(m*m) && n/(m*m) < 30 )
    printf("BMI = %lf (肥満)\n", n/(m*m) );
  if ( 30 <= n/(m*m) )
    printf("BMI = %lf (高度肥満)\n", n/(m*m) );


  return 0;/*終わりを示す*/
}
