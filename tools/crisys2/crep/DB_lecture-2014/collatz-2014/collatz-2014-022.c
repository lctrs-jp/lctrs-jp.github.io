#include <stdio.h>

int main()
{
  int p, q, r;

  printf("２以上の整数を入力してください:");
  scanf("%d", &p);

  printf("%d", p);
  for(;p != 1;){
    if( p % 2 == 0)
      p = p / 2;
    else
      p = 3 * p + 1;
    printf("->%d",p);
  }
  printf("\n");

  return 0; 
}
