#include <stdio.h>

int sum2(int x);

int sum1(int x){
  int y=0;  

  if(x<0) return(0);
  
  while(x>=0){
    y+=x;
    x--;
  }

  return y;  
}

main(){
  int n;

  printf("Input a natural number: ");
  scanf("%d",&n);
  
  if(sum1(n)<0) printf("overflow\n");
  else  printf("result by sum1: %d \n", sum1(n));
  if(sum2(n)<0) printf("overflow\n");
  else  printf("result by sum2: %d \n", sum2(n));
}

int sum2(int x){

  if(x<=0) return(0);

  return x+sum2(x-1);
}
