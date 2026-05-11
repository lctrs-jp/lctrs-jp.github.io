#include<stdio.h>

int sum(int a,int b);
int subtract(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulus(int a,int b);
int power(int a,int b);

//ポインタ配列を初期化する
int (*p[6]) (int x,int y) = {
	sum, subtract, mul, div,modulus, power
};

int main(void){
	int result;
	int i, j, op;
	
	printf("2つの数を入力してください：");
	scanf("%d%d",&i, &j);
	printf("0:加算　１：減算　２：乗算　３：除算 4:剰余 5:羃乗\n");
	do{
		printf("演算の番号を入力してください：　");
		scanf("%d",&op);
	}while((op < 0) || (op > 5));
	
	result = (*p[op]) (i, j);
	printf("%d\n",result);
	
	return 0;
}

int sum(int a,int b){
	return a + b;
}

int subtract(int a,int b){
	return a - b;
}

int mul(int a,int b){
	return a * b;
}

int div(int a,int b){
	if(b){
		return a / b;
	}
	else return 0;
}

int modulus(int a,int b){
	if(a<b){
		return a;
	}else{	
		return a % b;
	}
}

int power(int a,int b){
	int i;
	int c = 1;
	if(b==0){
		return 1;
	}
	for(i=0;i<b;i++){
		c = c * a;
	}
	return c;
}
