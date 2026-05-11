#include <stdio.h>

int sum1(int n){
	int i,sum = 0;

	if (n > 0){
		for(i = 1; i <= n; i++){
			sum += i;
		}
	}
	return (sum);
}

int sum2(int n){
	if (n < 1){
		return(0);
	} else if (n == 1){
		return(1);
	} else {
		return(n + sum2(n-1));
	}
}

int main(void){
	int num;

	printf("Input a natural number: ");
	scanf("%d",&num);

	printf("sum1   %d\n",sum1(num));
	printf("sum2   %d\n",sum2(num));

	return 0;
}
