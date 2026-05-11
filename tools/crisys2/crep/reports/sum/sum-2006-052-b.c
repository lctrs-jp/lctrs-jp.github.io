#include <stdio.h>

int sum1 (int n){
	int i,s;
	s = 0;
	if (n<0) return 0;
	else {
		for (i = 0;i <= n;i++)
			s = s + i;
		return s;}
}

int sum2 (int n){
	if (n<0) return  0;
	else return n + sum2(n - 1);
}

main () {
	int n;
	printf("Input a natural number:");
	scanf("%d",&n);
	printf("result by sum1: %d\n",sum1(n));
	printf("result by sum2: %d\n",sum2(n));
}
