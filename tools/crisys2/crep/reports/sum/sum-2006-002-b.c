#include <stdio.h>
int num,i,answer;

int sum2(int num);

int sum1(int num){
	if(num < 0){
		return 0;
	}else{
		answer = 0;
		for(i=0;i<=num;i++){
			answer = answer + i;
		}return answer;
	}
}

main(){
	printf("Input a natural number: ");
	scanf("%d",&num);
	printf("sum1(%d): %d\n",num,sum1(num));
	printf("sum2(%d): %d\n",num,sum2(num));
}

int sum2(int num){
	if(num <= 0){
		return 0;
	}else if(num == 1) {
		return 1;
	}else{
		return num + sum2(num-1);
	}
}
