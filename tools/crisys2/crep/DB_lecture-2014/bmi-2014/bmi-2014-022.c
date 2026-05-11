#include<stdio.h>
int main()
{
  float c;/*身長*/
  int g;/*体重*/
  printf("あなたの身長(m)を入力してください。\n");
  scanf("%f" , &c );
  printf("あなたの体重(kg)を入力してください。\n");
  scanf("%d", &g );
  printf("あなたのBMIは%fです。\n", g / (c * c));
  return 0;
} 
