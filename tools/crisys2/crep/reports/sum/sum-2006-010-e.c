#include <stdio.h>

int sum1(int n);
int sum2(int n);

main()
{
	int n;
	printf("Imput natural number N : ");
	scanf("%d",&n);
	printf("sum1:the sum total of 0 to %d = %d\n",n,sum1(n));
	printf("sum2:the sum total of 0 to %d = %d\n",n,sum2(n));
}

int sum1(int n)
{
	int sum=0;
	if(n<0)
	{
		return 0;
	}
	else
	{
		while(n>=0)
		{
			sum+=n;
			n--;
		}
		return sum;
	}
}

int sum2(int n)
{
	if(n<0)
	{
		return 0;
	}
	else
	{
		if(n==0)
		{
			return 0;
		}
		else
		{
			return n+sum2(n-1);
		}
	}
}
