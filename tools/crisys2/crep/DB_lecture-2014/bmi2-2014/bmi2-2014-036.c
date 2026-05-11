#include <stdio.h>

int main()
{
  double l; /* 身長（m）を表す変数 */
  double w; /* 体重（kg）を表す変数 */
  double bmi;

  printf("あなたの身長を入力してください(m):");
  scanf("%lf", &l );
  printf("あなたの体重を入力してください(kg):");
  scanf("%lf", &w );
  bmi = w / ( l * l );
  
  if ( bmi >= 30 )
    printf("bmi = %lf (高度肥満)\n", bmi);
  else if ( bmi >= 25 )
    printf("bmi = %lf (肥満）\n", bmi);
  else if ( bmi>= 18.5 )
    printf("bmi = %lf (標準) \n", bmi);
  else
    printf("bmi = %lf (痩せ) \n", bmi);

  return 0;
}
