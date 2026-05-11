#include <stdio.h>

int fastfib(int n){
	int a1,a2,sum,i;
	a1 = 1;
	a2 = 0;
	sum = 0;
	if( (n>0) && (n<47)){
		sum = 1;
		for(i=1;i<n;i++){
			sum = a1 + a2;
			a2 = a1;
			a1 = sum;
		}
	}
	return sum;
}

int main(){
	int i,j;
	printf("Please input a number n (1 <= n <= 46)\n");
	scanf("%d",&j);
	i=fastfib(j);
	if( (j>=0) && (j<47) ){
		printf("  fibfast(%d) : %d \n",j,i);
	}else{
		printf("Incorrect number !\n");
	}
}
