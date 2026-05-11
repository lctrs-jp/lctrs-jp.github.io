#include<stdio.h>

int fastfib(int x){
  int i,p=1,q=0;
  if(x==0)p=0;
  else if(x==1)p=1;
  else{
    for(i=1;i<x;i++){
      p=p+q;
      q=p-q;
    }
  }
  return(p);
}

main(){
  int i,x;
  printf("Input a natural number:\n");
  scanf("%d",&x);
  if(x<0){
    printf("Input a non-negative integer.\n");
    exit(1);
  }
  i=fastfib(x);
  printf("%dth Fibonacci number: %d\n",x,i);
}

