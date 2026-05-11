#include <stdio.h>

int main()
{
  float w, h;  
  printf("体重(kg)を入力してください。\n");
  scanf("%f", &w );
  printf("身長(m)を入力してください。\n");
  scanf("%f", &h );
  float b;
  b = w / ( h * h );
  printf("あなたのBNIは %f です。\n", b );
  return 0;
}
