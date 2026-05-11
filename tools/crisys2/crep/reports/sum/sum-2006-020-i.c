#include <stdio.h>

int sum2(int n);

int sum1(int n){
  int i,sum=0;
  
  if(n<0){
    return 0;
  }
  
  for(i=0;i<=n && sum>=0;i++){
    sum+=i;
  }
  
  if(sum<0){
    return -1;
  }

  return sum;
}

int main(){
  int num,result;

  printf("Input a natural number: ");
  scanf("%d",&num);
  
  result=sum1(num);
  printf("result by sum1: ");
  if(result==-1){
    printf("overflow\n");
  }else{
    printf("summation to %d %d\n",num,result);
  }
  
  result=sum2(num);
  printf("result by sum2: ");
  if(result==-1){
    printf("overflow\n");
  }else{
    printf("summation to %d %d\n",num,result);
  }

  return 0;
}

int sum2(int n){
  static int sum;
  
  if(n<0){
    return 0;
  }
  
  if(n==0){
    return 0;
  }
  
  sum=sum2(n-1);
  
  if(sum<0){
    return -1;
  }
  
  sum+=n;
  
  if(sum<0){
    return -1;
  }

  return sum;
}
