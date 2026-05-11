#include<stdio.h>
int sum2( int n );
int sum1( int n ){
  if(n < 0){
    return 0;
  }
  int cnt;
  int data = 0;
  for(cnt = 0;cnt <= n;cnt++){
    data = data + cnt;
  }
  return data;
}

main(){
  int i;
  printf("Input a natural number\n");
  scanf("%d",&i);
  printf("result by sum1: %d\n",sum1(i));
  printf("result by sum2: %d\n",sum2(i));
}

int sum2(int n){
  if(n <= 0){
    return 0;
  }
  else return (n + sum2(n-1));
}
