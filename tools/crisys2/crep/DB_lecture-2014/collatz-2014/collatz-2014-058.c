#include <stdio.h>

int ken(int n)

int main()
{
  int n;

  printf("２以上の数を入力してください。:");
  scanf("%d",n)
    printf("%d->",n)
    while (n!=1){
      n=ken(n);
      printf("%d->",n);
    }
  printf("1");
  return 0;
}

int ken(int n)
{

  if (n%2==0)
    n=n/2;
  else if (n%2==1) 
    n=n*3+1;

  return n;
}
