#include<stdio.h>

int sum2(int m,int n);

int main(void){
  
  int m,n;

  printf("Input two integers\n");
  printf("1st: ");
  scanf("%d",&m);
  printf("2nd: ");
  scanf("%d",&n);

  if(sum2(m,n) > 0)
    printf("summation from %d to %d is %d.\n", m, n, sum2(m,n));
  else
    printf("summation from %d to %d is %d.\n", n, m, sum2(n,m));
  
  return 0;

}

int sum2(int m,int n){

  int sum = 0;

  if(m <= n){
    while(1){
      sum += m;
      m++;
      if(m > n)
	break;
    }
    return sum;
  }else
    return 0;

}
