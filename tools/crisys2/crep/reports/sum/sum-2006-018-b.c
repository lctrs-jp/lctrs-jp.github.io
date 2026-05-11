#include <stdio.h>

int sum1(int n) 
{
	int i;
	int k;
	k = 0;
	if(n<0){
       	return(0);
	} else {
		for(i=0; i<=n; i++)  
	{     	k = k + i; }
	} return k;
}

int main()
{
	int num;
	printf("num? \n");
	scanf("%d",&num); 
	printf("result by sum1: %d\n result by sum2: %d\n",sum1(num),sum2(num));
	return(0);
}

int sum2(int n) 
{
	if(n<=0){
       	return(0);
	} else {
		return(sum2(n-1)+n); 
	}
}
