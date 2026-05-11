#include <stdio.h>
float bmi(int n, float m);

int main()
{
  int n; /* 体重を表す変数 */
  float m; /* 身長を表す変数 */

  printf("Input your weight: ");
  scanf("%d", &n );
  printf("Input your height: ");
  scanf("%f", &m );

  if( n / (m*m) >= 30 )
    printf("BMI = %f (高度肥満)\n", bmi(n,m) );
  else
    if( n / (m*m) >= 25 )
      printf("BMI = %f (肥満)\n", bmi(n,m) );
    else
      if( n / (m*m) >= 18.5 )
        printf("BMI = %f (標準)\n", bmi(n,m) );
      else
        printf("BMI = %f (やせ)\n", bmi(n,m) );
  return 0;
}

/* BMIを計算する関数　*/
float bmi(int n, float m)  // bmiの本体
{
  return n / (m*m);
}
