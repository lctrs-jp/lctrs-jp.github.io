#include <stdio.h>

int fastfib(int n);

int main(){
  int fib;
  int n;

  printf("Input a natural number: ");
  scanf("%d", &n);
  fib = fastfib(n);
	
  if(fib == -1){
    printf("A non-negative integer was inputted.\n");
  }else if(fib == -2){
    printf("Overflow\n");
  }else{
    printf("%dth Fibonacci number: %d\n", n, fib);
  }
	
  return 0;
}


int fastfib(int n){
  int previous1Fib = 1; // Fib(n - 1)
  int previous2Fib = 0; // Fib(n - 2)
  int presentFib; // Fib(n)
  int i;
	
  if(n < 0){
    return -1;
  }else if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    for(i = 1; i < n; i++){
      presentFib = previous1Fib + previous2Fib;
			
      if(presentFib < previous1Fib){
	return -2;
      }
      previous2Fib = previous1Fib;
      previous1Fib = presentFib;
    }
  }

  return presentFib;
}
