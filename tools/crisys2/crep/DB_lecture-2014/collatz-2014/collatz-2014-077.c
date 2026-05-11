#include <stdio.h>

int main(void)
{
  int n;

  printf("整数を入力してください\n");
  scanf("%d", &n);

  for(; n != 2;){
    if(n % 2 == 0)
      n = n / 2;
    else if(n % 2 == 1)
      n = n * 3 - 1;

    printf("%d -> ", n);
  }
  printf("1");

    return 0;
}
