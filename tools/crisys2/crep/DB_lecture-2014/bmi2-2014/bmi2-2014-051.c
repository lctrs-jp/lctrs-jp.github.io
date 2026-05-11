#include <stdio.h>

float func(float height, float weight);
 
int main(void)
{
  float w, h, BMI;

  printf("身長を入力してください(m)");
  scanf("%f",&h);
  printf("体重を入力してください(Kg)");
  scanf("%f",&w);

  BMI = func(h, w);

  if (BMI < 18.5)
    printf("肥満度は痩せです\n");
  else if (BMI < 25)
    printf("肥満度は標準です\n");
  else if (BMI < 30)
    printf("肥満度は肥満です\n");
  else 
    printf("肥満度は高度肥満です\n");

    return 0;

}
   
  float func(float height, float weight)
{
 return weight / (height * height);
}
