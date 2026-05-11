#include <stdio.h>

int sum1(int n){
  int s = 0;
  int i;
  for(i=0;i<=n;i++){
    s = s + i;
  }
  return(s);
}

int main()
{
  int n,s1;
  printf("Input a natural number: ");
  scanf("%d",&n);
  if(n<=0){
    printf("Input a natural number!\n"); 
  }else{
    printf("result by sum1: %d\nresult by sum2: %d\n", sum1(n), sum2(n));
  }
  return 0;
}

int sum2(int n){
  if(n==0){
    return(0);
  }else if(n<0){
    return(0);
  }else{
    return(sum2(n-1)+n);
  }
}
