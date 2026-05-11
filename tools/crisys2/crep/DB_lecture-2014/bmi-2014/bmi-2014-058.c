#include <stdio.h>

int main()
{
  float w_weight;
  float h_height;
  float b_bmi;

  printf("体重を入力(kg)");
  scanf("%f", &w_weight );

  printf("身長を入力(m)");
  scanf("%f", &h_height );
  
  b_bmi = w_weight / (h_height * h_height) ;

  printf("BMI = %f\n", b_bmi );

  return 0;
}
