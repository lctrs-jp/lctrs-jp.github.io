#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int modulus(int a, int b);
int power(int a, int b);

int (*p[6]) (int x, int y) =
{
	sum, subtract, mul, div, modulus, power
};

int main(void)
{
	int result;
	int i, j, op;
	
	printf("2つの数字を入力してください\n");
	scanf("%d%d", &i, &j);
	for(;;)
	{
		printf("演算の番号を入力してください\n");
		printf("0:加算 1:減算 2:乗算 3:除算 4:余り 5:べき乗\n");
		scanf("%d", &op);
		if(0 <= op && op <= 5)
			break;
	}
	
	result = (*p[op]) (i, j);
	printf("%d", result);
	
	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	if(b != 0)
		return a / b;
	else
		return 0;
}

int modulus(int a, int b)
{
	if(b != 0)
		return a % b;
	else
		return 0;
}

int power(int a, int b)
{
	int c = 1;
	
	for(;b != 0;b--)
	{
		c = c * a;
	}
	
	return c;
}

