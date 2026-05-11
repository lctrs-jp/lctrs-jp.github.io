#include <stdio.h>
int sum2(int n);

int sum1(int n){
        int i,sum;
        for (i=n;i>=0;i--) sum=sum+i;
        return sum;
}

main(){
	int n;
	printf("Input a natural number: ");
	scanf("%d",&n);
		printf("result by sum1: %d \n",sum1(n));
		printf("result by sum2: %d \n",sum2(n));
}

int sum2(int n){
	if(n<=0) return 0;
	return(n+sum2(n-1));
}
