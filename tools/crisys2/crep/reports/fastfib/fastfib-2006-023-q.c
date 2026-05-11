#include <stdio.h>

int fastfib(int n);

int main(){
  int num,result;

  printf("Input a natural number: ");
  scanf("%d",&num);

  result=fastfib(num);
  if(result==-1){
    printf("Overflow.\n");
  }else{
    printf("Fib(%d) = %d\n",num,result);
  }

  return 0;
}

int fastfib(int n){
  int pre1=1,pre2=0,val=0,i;

  if(n<=0){
    return 0;
  }

  if(n==1){
    return 1;
  }

  for(i=2;i<=n && val>=0;i++){
    val=pre1+pre2;
    pre2=pre1;
    pre1=val;
  }

  if(val<0){
    return -1;
  }

  return val;
}
