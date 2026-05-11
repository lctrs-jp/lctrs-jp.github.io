#include <stdio.h>
float bmi(float y, int x);

int main()
{
  float h;  /* 身長(h) */
  int m;  /* 体重(m) */
  printf("身長(m)は？");
  scanf("%f", &h );
  printf("体重(kg)は？");
  scanf("%d", &m );
  
  if( bmi(h,m) >= 30) /* 高度肥満の時の条件 */
    printf(" BMI = %f (高度肥満)\n", bmi(h,m) );
  else{ /* BMIが肥満の時の条件 */
    if( bmi(h,m) >= 25)
      printf(" BMI = %f (肥満)\n", bmi(h,m) );
    else{ /* 標準の時の条件 */
      if( bmi(h,m) >= 18.59)
	printf(" BMI = %f (標準)\n", bmi(h,m) );
      else /* やせの時の条件 */
	printf(" BMI = %f (やせ)\n", bmi(h,m) );
    }
  }

  return 0;
}

float bmi(float y, int x) /* bmiの計算 */
{
  float z;
  z = x/(y*y); /* BMI = 体重/(身長*身長) */
  return z;
}
