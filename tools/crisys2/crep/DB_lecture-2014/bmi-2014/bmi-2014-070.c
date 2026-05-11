#include <stdio.h>

int main()
{
  float x_weight;
  float y_length;
  float z_bmi;

  printf("体重を入力してください(kg)");
    scanf("%f", &x_weight);

    printf("身長を入力してください(m)");
    scanf("%f", &y_length);

    z_bmi = x_weight / (y_length * y_length);

    printf("あなたのBMI: %f", z_bmi);

  return 0;
}
