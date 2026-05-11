#include <stdio.h>

int fastfib(int n);

int main()
{
    int n;
    printf("Input a natural number: ");
    scanf("%d",&n);
    if(fastfib(n) == 0)
      printf("Input a positive number. (Fib(%d) = 0)\n",n);
    else
      printf("Fib(%d) = %d\n",n,fastfib(n));
    return 0;   
}

int fastfib(int n)
{
    int a, b, num, i;
    if(n<=0) return 0;
    if(n==1 || n==2) return 1;
    a = 1;
    b = 1;
    for(i=3;i<=n;i++){
      num = a + b;
      a = b;
      b = num;
    }
    return num;
}

