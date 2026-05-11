#include <stdio.h>

int sum2(int n);

int sum1(int n){

  int i,sum=0;

  if(n < 0){
    return 0;
  }else{
    for(i=0;i<=n;i++){
      sum=sum + i;
    }
  }

  return sum;
}

int main(){

  int num,sum_1,sum_2;

  printf("Input a positive integer: ");
  scanf("%d",&num);

  sum_1 = sum1(num);
  sum_2 = sum2(num);

  printf("result by sum1: %d\n",sum_1);
  printf("result by sum2: %d\n",sum_2);

  return 0;

}

int sum2(n){

  if(n < 0){
    return 0;
  }

  n = n + sum2(n-1);
  return n;
}
