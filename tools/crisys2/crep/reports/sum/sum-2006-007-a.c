#include <stdio.h>

int sum1(int n){
  int i,p=0;
  if(n <= 0){
    p=0;
  }else{
    for(i=0;i<=n;i++){
      p = p + i;
    }
  }
  return p;
}

int sum2(int n);

main(){
  int n;
  printf("Input a natural number: ");
  scanf("%d",&n);
  printf("result by sum1: %d\n",sum1(n));
  printf("result by sum2: %d\n",sum2(n));
  return 0;
}

int sum2(int n){
  int i,p=0;
  if(n<=0){
    p=0;
  }else{
    p = n + sum2(n-1);
  }
  return p;
}
