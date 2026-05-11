
int sum1(int n);
int sum2(int n);

int sum1(int n)
{
    int i = 0;			
    int sum = 0;		

    if (0 > n) {
	return 0;
    } else {
	for (i = 0; i <= n; i++) {
	    sum += i;
	}
    }

    return sum;
}

int main()
{
    int num = 0;		

    printf("input a integer --> ");
    scanf("%d", &num);

    printf("the summation by \"sum1\": %d\n", sum1(num));
    printf("the summation by \"sum2\": %d\n", sum2(num));

    return 0;
}

int sum2(int n)
{
    if (0 >= n) {
	return 0;
    } else {
	return (n + sum2(n - 1));
    }
}
