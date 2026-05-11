#include <stdio.h>

int function(int n);

int main(void)
{
  int i;
  printf("2以上の整数を入力して下さい: \n");
  scanf("%d ",i);

  printf("%d", function);

  return 0;
}

int function(int n)
{
  int x, s;

  x = n; /* xの値が1になるまで計算を繰り返す */
  while( x > 1){
    s = 0;
    while(x > 0){
      if((x % 2) == 0)
        s = x / 2;
      else
        s = 3*x + 1;
    }
    x = s;
    printf("%d", x);
  }

  return x;
}
