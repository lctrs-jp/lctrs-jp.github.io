#include<stdio.h>

int main(void)
{
  int n;
  printf("２以上の整数を入力してください。");
  scanf("%d",&n);
  for(;n!=1;){
    if(n%2==1){
      n=n/2;
    }
    printf("%d",n);
      if(n%2==0){
      n=n*3+1;
      }
      printf("%d",n);
  }
 
  return 0;
}

