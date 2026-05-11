#include <stdio.h>

int main()
{
  int n,i;

  //整数の入力
  printf("2以上の整数を入力してください: ");
  scanf("%d",&n);

  //過程の最初の表示
  printf("%d",n);

  //操作および過程の表示
  for(; n>1;){

    if(n%2==0)
      n = n/2;
  
    else
      n = 3*n + 1;

    printf(" -> %d", n);
  }

  //改行
  printf("\n");

  return 0;
}
