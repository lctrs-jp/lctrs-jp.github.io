#include <stdio.h>

int sum2(int);

int sum1(int num){
	int sum = 0;
	if(num > 0){
		while(num != 0){
			sum = sum + num;
			num--;
		}
		return sum;
	}else{
		return 0;
	}
}

int main(){
	int input = 0;
	
	printf("Input a natural number: ");
	scanf("%d", &input);

	printf("result by sum1: %d\n", sum1(input));
	printf("result by sum2: %d\n", sum2(input));

	return 0;
}

int sum2(int num){
	if(num > 0){
		num = num + sum2(num - 1);
		return num;
	}else{
		return 0;
	}
}
