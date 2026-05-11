#include <stdio.h>

int sum2(int i);

int sum1(int i)
{
	int k,suma;
	suma=0;
	k=0;

	if(i<=0)
	{
		return(0);
	}
	else
	{
	while(k<=i)
	{
		suma=suma+k;
		k=k+1;
	}

	return (suma);
        }
}

int main()
{
	int num;
	printf("Value of n:");
	scanf("%d",&num);

      	printf("summation to %d by sum1:%d\n",num,sum1(num));
       	printf("summation to %d by sum2:%d\n",num,sum2(num));

	return 0;
}

int sum2(int i)
{
	if(i<=0)
	{
		return(0);
	}
	else if(i==1)
	{
		return(1);        
        }
        else
        {
		return(i+sum2(i-1));
	}
}
