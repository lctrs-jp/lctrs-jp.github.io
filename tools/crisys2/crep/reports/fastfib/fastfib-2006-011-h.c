#include <stdio.h>

int fastfib(int n)
{
  int now,next,i,tmp;
	
  if(n <= 0){
    return(0);
  }else if(n == 1){
    return(1);
  }else{
    now  = 1;			//fastfib(1)=1
    next = 1;			//fastfib(2)=1

    for(i=3;i<=n;i++){
      tmp   = now;
      now   = next; 
      next += tmp;
    }
  }
  return(next);
}

int main(void)
{
  int num;

  printf("Input a natural number: ");
  scanf("%d",&num);
  if(num < 0){
    printf("A negative integer was inputted. Input a natural number (Fib(%d) = 0)\n",num);
    return(0);
  }else if(num > 46){
    printf("overflow. Input a number less than equal to 46.\n");
    return(0);
  }else{
    printf("%dth Fibonacci number: %d\n",num,fastfib(num));
    return(0);
  }
}
