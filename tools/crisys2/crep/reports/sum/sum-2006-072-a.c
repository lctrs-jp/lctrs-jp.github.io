#include<stdio.h>
int sum2(int n);

int sum1(int n)
{
	int i, ans;
	if(n > 0){
		for(i=1; i<=n; i++){
			ans += i;
		}
		return ans;
	}else return 0;
}

main()
{
	int num;
	printf("Input a natural number>");
	scanf("%d", &num);

	printf("result by sum1: %d\nresult by sum2: %d\n", sum1(num), sum2(num));
}

int sum2(int n)
{
	if(n<0) return 0;
	if(n==0) return 0;
	return n + sum2(n-1);
}
