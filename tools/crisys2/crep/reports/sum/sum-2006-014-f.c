#include<stdio.h>

int sum1(int n);
int sum2(int n);

int main(){
  int num;
  printf("Input a natural number: ");
  scanf("%d",&num);
  printf("result by sum1: %d\n",sum1(num));
  printf("result by sum2: %d\n",sum2(num));

  return 0;
}

int sum1(int n){
  int sum;
  if(n<0){
    return 0;
  }

  for(sum=0;n>0;n--){
    sum+=n;
  }

  return sum;
}

int sum2(int n){
  if(n<=0){
    return 0;
  }else{
    return n+sum2(n-1);
  }
}
