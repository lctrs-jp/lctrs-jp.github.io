#include <stdio.h>

int main()
{
  float weight; /*体重を表す変数*/
  float height; /*身長を表す変数*/
  
  printf("あなたの体重を入力してください");
  scanf("%f", &weight );
  printf("あなたの身長を入力してください");
  scanf("%f", &height );
  printf("あなたのBMIは　%f", weight / (height*height));

    return 0;
} 
