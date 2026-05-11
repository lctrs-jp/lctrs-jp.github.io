#include<stdio.h>

int main()
{
	long int i;
	
	printf("２以上の整数を入力してください");
	scanf("%d" , &i);
	
	for(;;)
	{
		if(i % 2 == 0)
		i = i/2;
		
		else if(i % 2 != 0)
		i = (i * 3) + 1;
		
		printf("%d -> " , i);
		
		if(i == 1)
		break;
	}
	
	return 0;
}

	