#include <stdio.h>

int fastfib(int n);

main(){
  int i;
  printf("Input a natural number: ");
  scanf("%d",&i);

  if(i<=0){
    printf("Fib(%d)=0\n",i);
  }else if(i==1){
    printf("Fib(1)=1\n");/*Fib(1)=1*/
  }else{
    printf("Fib(%d)=%d\n",i,fastfib(i));
  }
  return 0;
}

int fastfib(int n){
  int tmp1,tmp2,tmp3,i;

  tmp1=0;
  tmp2=1;
  tmp3;

  for(i=2;i<=n;i++){
    tmp3=tmp2;
    tmp2=tmp1+tmp2;
    tmp1=tmp3;
  }

  return (tmp2);
}
