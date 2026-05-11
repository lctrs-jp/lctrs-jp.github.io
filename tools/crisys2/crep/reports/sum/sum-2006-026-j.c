#include<stdio.h>

int sum2(int n);

int sum1(int n)
{
    int i;
    int sum = 0;            

    if(n <= 0){             
        return 0;
    } else {
        for (i = 0;(n - i) > 0;i++){
            sum = sum + (n - i);}      
    }
        return sum;
}

main()
{
    int n;

    printf("Input a natural number. Summation from 0 to the input will be displayed.\n");
    scanf("%d",&n);
    printf("Summation from 0 to %d is\ndue to sum1, %d\ndue to sum2, %d\n",n,sum1(n),sum2(n));
}

int sum2(int n)
{
    if(n <= 0){              
        return 0;
    } else {
        return(n + sum2(n-1));  
    }
}
