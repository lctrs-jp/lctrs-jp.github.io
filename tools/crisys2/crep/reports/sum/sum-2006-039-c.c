#include <stdio.h>

int sum1(int n)
{
     int sum1, i ;
     
     sum1=0;
     
     for(i=1; i<=n; i++)
        sum1 = sum1 + i;
     
     return sum1 ;
}

main()
{   
     int n;

     printf("Input a natural number:");
     scanf("%d",&n);

     printf("result by sum1:%d\n", sum1(n));
     printf("result by sum2:%d\n", sum2(n));

     return 0;
}
    
int sum2(int n)
{
     if (n<=0) return 0;
    
     else if (n==1) return 1; 

     else return sum2(n-1)+n;
}
