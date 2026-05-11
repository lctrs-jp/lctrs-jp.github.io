#include <stdio.h>

int main()
{
  float height, weight;

  printf("身長(m)を入力してください：");
  scanf("%f", &height);
  printf("体重(kg)を入力してください：");
  scanf("%f", &weight);
  printf("あなたのBMIは %.2f です。\n", weight/(height*height));
  
  return 0;
}
