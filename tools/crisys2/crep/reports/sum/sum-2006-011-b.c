#include <stdio.h>

int sum2(int n);

int sum1(int n)
{
	int i, sum = 0;
	if(n < 0){
		return 0;
	}else{
		for(i = 1; i <= n; i++){
			sum = sum + i;
		}
		return sum;
	}
}

main()
{
	int num;
	printf("Input a natural number: ");
	scanf("%d", &num);
	printf("result by sum1: %d\n",sum1(n));
	printf("result by sum2: %d\n",sum2(n));
}


int sum2(int n)
{
	if(n <= 0){
		return 0;
	}else{
		return n + sum2(n - 1);
	}
}
