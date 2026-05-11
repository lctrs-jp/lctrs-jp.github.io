#include <stdio.h>

int main()
{
  float weight; /* 体重[㎏]を表す変数*/
  float height; /*身長[ｍ]を表す変数*/
  
  /* BMI指数を計算する*/
  printf("あなたの体重[㎏]を入力してください:");
  scanf("%f", &weight);
  printf("あなたの身長[ｍ]を入力してください:");
  scanf("%f", &height);

  printf("あなたのBMI指数は%fです\n", weight/height/height);

  return 0;
}
