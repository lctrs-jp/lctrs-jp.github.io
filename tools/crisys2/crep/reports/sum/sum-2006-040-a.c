#include<stdio.h>

int sum1(int n)
{
	int i,j=0;
	if(n <= 0){
		return(0);
	}else{
		for(i = 1;i <= n;i++){
			j=j+i;
		}
		return(j);
	}
}

int main()
{
	int num;
	printf("Input a number (0 or a natural number):");
	scanf("%d",&num);
	
	printf("result by sum1:%d\n",sum1(num));
	printf("result by sum2:%d\n",sum2(num));
	
	return 0;
}

int sum2(int n)
{
	if(n <= 0){
		return(0);
	}else{
		return(n + sum2(n-1));
	}
}
