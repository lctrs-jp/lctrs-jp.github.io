#include <stdio.h>

int main()
{
  int weigh;
  float height;

  printf("体重(kg)を入力してください: ");
  scanf("  %d", &weigh );
  
  printf("身長(m)を入力してください: ");
  scanf(" %f", &height );
  
  printf("BMIは %f です" ,weigh/(height * height));

  return 0;
}
