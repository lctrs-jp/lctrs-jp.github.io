#include <stdio.h>

int sum1(int n)
{
  if(n>=0){
    int i,k;
    k = 0;
    for(i=0;i<=n;i++){
       k = k + i;
    }
    return k;
  }else{
    return 0;
  }
}

int main()
{
  int num;
  printf("Input a natural number: ");
  scanf("%d",&num);
  printf("result by sum1: %d \n",sum1(num));
  printf("result by sum2: %d \n",sum2(num));
  return 0;
}

int sum2(int n)
{
  if(n>=1){
    int i,k;
    return(n + sum2( n-1 ));
  }else{
    return 0;
  }
}
