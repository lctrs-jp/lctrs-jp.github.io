#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int len,j;
	double pow26;
	long int ans = 0;
	
	if(argc != 2 || strlen(argv[1])>5 )
	{
		printf("エラー");
		return 0;
	}
	
	
	len = strlen(argv[1]);
	
	for(j=0;j<len;j++)
	{
		pow26 = pow(26,len-(j+1));
		ans = ans + (*(argv[1]+j) - 64)*(int)pow26;
	}
	
	printf("%d\n", ans);
	return 0;
}

