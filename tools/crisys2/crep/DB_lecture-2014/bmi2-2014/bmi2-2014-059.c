#include <stdio.h>
float bmi(float w, float h);

int main()
{
  float w;
  float h;

  printf("体重を入力(kg)");
  scanf("%f", &w );

  printf("身長を入力(m)");
  scanf("%f", &h );

  if(bmi(w,h) < 18.5)
    printf("BMI = %f やせ\n", bmi(w,h));
  if(18.5 <= bmi(w,h) && bmi(w,h) < 25)
    printf("BMI = %f 標準\n", bmi(w,h));
  if(25 <= bmi(w,h) && bmi(w,h) < 30)
    printf("BMI = %f 肥満\n", bmi(w,h));
  if(bmi(w,h) > 30)
    printf("BMI = %f 高度肥満\n", bmi(w,h));

  return 0;
}

float bmi(float w, float h)
{
  float b;
  b = w /( h * h );
  return b;
}
