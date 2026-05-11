#include <stdio.h>

int fastfib(int n);

main()
{
	int n, result;

	printf("Input a natural number: ");
	scanf("%d", &n);
	
	result = fastfib(n);
	
	if(result > 0) {
	  printf("%dth Fibonacci number: %d\n", n, result);
	}
	else if(result == 0) {
		printf("Input a positive number (Fib(%d) = 0)\n", n);
	}
	else {
	  printf("Overflow.\n");
	}
}

int fastfib(int n)
{
  int k1=1, k2=0, k3=0; 
	
  if(n < 0) {
    return 0;
  }
  else if(n == 0) { 
    return 0;
  }
  else if(n == 1) {
    return 1;
  }
  else {
    for( ; n > 1; n--) {
      k3 = k1 + k2;
      k2 = k1;
      k1 = k3;
    }
		
    return k3;
  }
}
