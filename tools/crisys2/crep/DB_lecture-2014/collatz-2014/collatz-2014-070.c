#include<stdio.h>

int main()
{
  int n;
  printf("2以上の整数を入力してください\n");
  scanf("n=%d\n",&n);

  for(;n!=1;){
 
  if(n%2==0)
    n=n/2;

  else 
    n=3*n+1;
  printf("%d",n);
}

  return 0;
}
