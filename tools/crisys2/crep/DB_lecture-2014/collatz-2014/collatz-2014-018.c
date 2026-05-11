#include<stdio.h>
#include<string.h>

int main()
{
  int n;
  printf("数を入力して下さい\n");
    scanf("%d",&n);
    printf("%d->",n);
    while(n>2){
      if(n%2==0){
      n=n/2;
    printf("%d->",n);
      }
      else{
      n=n*3+1;
      printf("%d->",n);
    }     
    }  
    printf("1\n");
 return 0;
}
