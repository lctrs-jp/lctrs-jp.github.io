#include<stdio.h>

int main()
{
  int x,i; 

  printf("整数を入力してください(2以上):");
  scanf("%d",&x); 

  for(;x!=1;){
    printf("%d->",x);
    if(x%2==0)
      x=x/2;
    else
      x=x*3+1;
  }
  printf("1");

  return 0;
}
