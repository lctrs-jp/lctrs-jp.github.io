#include <stdio.h>

int sum2(int n);

int sum1(int n){
  int x = 0;
  if(n <= 0){
    return 0;
  }
  while(n > 0){            
    x += n;
    n--;
  }
  return x;
}

main(){
  int num;
  printf("Input a number: ");
  scanf("%d", &num);
  printf("result by sum1: %d\n", sum1(num));
  printf("result by sum2: %d\n", sum2(num));
}

int sum2(int n){
  int x;
  if(n <= 0){
    return 0;
  }
  x = n + sum2(n-1);       
  return x;
}
