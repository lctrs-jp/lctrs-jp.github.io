#include <stdio.h>

int sum2(int n); 

int sum1(int n)
{
	int result=0; 

	if(n >= 0) { 
		for( ; n >= 0; n--) {
			result += n;
        }
	} else { 
		result = 0;
	}

	return result;
}

main()
{
	int num, ans1, ans2; 

	printf("Input a natural number (more than equal 0): ");
	scanf("%d", &num); 

	ans1 = sum1(num);
	printf("result by sum1: %d\n", ans1);

	ans2 = sum2(num);
	printf("result by sum2: %d\n", ans2);
}

int sum2(int n)
{
	if(n > 0) { 
		return n+sum2(n-1);
	} else if(n == 0) { 
		return 0;
	} else { 
		return 0;
	}
}
