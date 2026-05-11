#include <stdio.h>

int sum1(int);

int main(){
  int input;   
  
  printf("Require to input a natural number: ");
  scanf("%d",&input);

  printf("result by sum1: %5d\n",sum1(input));
  printf("result by sum2: %5d\n",sum2(input));

  return 0;
}

int sum1(int n){

  if(n <= 0) return 0;

  n = (n + 1) * n / 2;
  
  return n;
}
                                                                               
int sum2(int n){

  if (n <= 0) return 0;

  return n + sum2(n-1);

}
