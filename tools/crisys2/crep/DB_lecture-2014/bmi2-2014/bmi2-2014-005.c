#include <stdio.h>

int main()
{
  float bmi, height, weight;

  printf("あなたの身長(cm)を入力してください：");
  scanf("%f", &height);
  printf("あなたの体重(kg)を入力してください：");
  scanf("%f", &weight);

  bmi = weight * 10000 / (height * height);

  printf("あなたのＢＭＩは %.2f です。\n", bmi);
  printf("あなたは");
  if(bmi < 18.5)
    printf(" やせ型 です。\n");
  if((bmi >= 18.5) && (bmi < 25))
    printf(" 標準体型 です。\n");
  if((bmi >= 25) && (bmi < 30))
    printf(" 肥満体型 です。\n");
  if(bmi >=30)
    printf(" 高度肥満体型 です。\n");

  return 0;
}
