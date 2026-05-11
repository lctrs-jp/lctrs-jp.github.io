#include <stdio.h>

int main(void)
{
  int n;

  printf("数字を入力してください　（2以上　3*2^53以下）: ");
  scanf("%d", &n);

  while(n !=1){
    if(n % 2 == 0)
      n = n / 2;
    else if(n % 2 == 1)
    n = n * 3 + 1;

    printf("%d\n", n);
  }

  return 0;
}
