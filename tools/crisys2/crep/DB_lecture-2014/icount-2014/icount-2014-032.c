#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;
	int count[10];
	char num[110];
	
	for(i = 0; i<10; i++)
		count[i] = 0;
	
	printf("数字列を入力して下さい(長さ100以下) :");

	fgets(num, 100, stdin);

	for(i=0; i<10; i++){
		for(j=0; j<strlen(num);j++){
			if(num[j] == i+48)
				count[i]++;
		}
		printf("%dは %d個含まれています.\n", i, count[i]);
	}
	
	return 0;
}
