#include <stdio.h>

int main(void)
{
  int n;

  printf("数を入力してください：");
  scanf("%d",&n);

  printf("%d",n);
  while(n!=1)
  {
    if(n%2==0)
      n /= 2;
    else
      n=3*n+1;
    printf(" -> %d",n);
  }
  printf("\n");

  return 0;
}
