#include<stdio.h>

int sum1( int n )
{
	int i,j;
	j=0;
		
	if(n >= 0){
		for(i=0;i<=n;i++){
			j=j+i;
		}
			return(j);
	}
	
	else return(0);
}

main()
{
	int num;
	printf("Input a natural number: ");		
	scanf("%d",&num);
	printf(" result by sum1: %d\n result by sum2: %d\n" ,sum1(num) ,sum2(num));
	}

int sum2( int n )
{
	if(n == 0) return(0);	             
	else if(n >= 1) return(n+sum2(n-1)); 
	else return(0);	                     
}
