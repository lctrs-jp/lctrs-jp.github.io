#include <stdio.h>

int cal(int x);

int main(void){
	int num;
	printf("2以上の整数を入力して下さい:");
	scanf("%d", &num);
	
	printf("%d", num);
	while(num != 1){
		num = cal(num);
		printf(" -> %d", num);
	}
	printf("\n");
	return 0;
}

int cal(int x){
	if(x % 2) return (x * 3 + 1);
	else return (x / 2);
}
