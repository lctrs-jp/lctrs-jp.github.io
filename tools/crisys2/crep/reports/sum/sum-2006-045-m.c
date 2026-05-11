#include <stdio.h>

int sum1(int num);
int sum2(int num);

int main() {
  int num;

  printf("Input an integer. Summation to the integer will be calculated.\n");
  scanf("%d", &num);
  printf("result by sum1: %d\n", sum1(num));
  printf("result by sum2: %d\n", sum2(num));

  return 0;
}

int sum1( int num) {
  if(num > 0){
   return  num + sum1(num - 1);   
  } else if(num < 0) {
    return 0;
  } else if(num == 0) {
    return 0;
  }
}

int sum2 (int num) {

  int a = 0;

  if (num > 0){
  for(num; num >= 0; num--) {
    a =  a + num;
  } return a;
  }  else {
    return 0;
  } 
}


    
