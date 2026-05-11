#include <stdio.h>
#include <math.h>
double fact(int n,double x){

  double g=1;
  int i;
  for(i=0;i<n;i++){
    g = g*x;
}
  return g;
}

int fastfib(int n)
{
  int f;
   
  f =( 1/sqrt(5.0))*(fact(n,(1+sqrt(5))/2)-fact(n,(1-sqrt(5))/2));
  return f;
}

main()   
{
  int n;
   printf("Input a natural number: ");
   scanf("%d",&n);
   if(n<0){
     printf("Input a positive number (Fib(%d)=0)\n",n);
   }
   else if(fastfib(n)<0) printf("Overflows.\n");
   else { 
     printf("%dth Fibonacci number: %d\n",n,fastfib(n));
   }

}
