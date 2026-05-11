#include <stdio.h>
double bmi(float x_height, float y_weight);

int main()
{
  float x_height;
  float y_weight;

  printf("身長を入力してください(m)");
  scanf("%f", &x_height);

  printf("体重を入力してください(kg)");
  scanf("%f", &y_weight);

  printf("あなたのBMIは %lf\n", bmi(x_height, y_weight) );

  if ( bmi(x_height, y_weight) >= 30){
    printf("あなたは高度肥満です\n");

  }else if ( bmi(x_height, y_weight) >= 25){
    printf("あなたは肥満です\n");

  }else if ( bmi(x_height, y_weight) >= 18.5){
    printf("あなたは標準です\n");

  }else{
    printf("あなたはやせです\n");
  }

  return 0;
}

double bmi(float x_height, float y_weight)
{
  return y_weight / (x_height * x_height);
}
