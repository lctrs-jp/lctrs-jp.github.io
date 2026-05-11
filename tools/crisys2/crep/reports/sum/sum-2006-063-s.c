#include <stdio.h>

int sum2(int n);

int sum1(int n){
	int num;
	num = n;

	if(n < 0){
		return (0);
	}else{
		for(n = n - 1 ; n > 0 ; n--){
			num = num + n;
		}
		return (num);
	}
}

	 int main(){
		int n;
		printf("Input a natural number:");
		scanf("%d",&n);
		printf("result by sum1: %d\n",sum1(n));
		printf("result by sum2: %d\n",sum2(n));
	}

int sum2(int i){
	if(i <= 0){
		return(0);
	}else{
 		return(i + sum2(i-1));    
	}
}
