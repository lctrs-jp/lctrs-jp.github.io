#include <stdio.h>
int main()
{
  int n=0;

  //整数の入力
  while(n<2){
    printf("整数を入力してください(n>=2)\n");
    scanf("%d", &n);
    if(n<2)
      printf("入力が不正です\n");
  }

  //操作および出力
  printf("%d",n);
  while(n!=1){
    if(n%2==0)
      n=n/2;
    else
      n=n*3+1;
    printf("->%d",n);
  }

  return;
}
