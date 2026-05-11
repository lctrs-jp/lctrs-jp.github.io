#include <stdio.h>

int main()
{
  float t ;
  float u ;
  printf("身長[m]を入力してください") ;
  scanf("%f",&t);
  printf("体重[kg]を入力してください") ;
  scanf("%f", &u);
  printf("あなたのBMIは %f\n",u/t/t);
 return 0;
}
