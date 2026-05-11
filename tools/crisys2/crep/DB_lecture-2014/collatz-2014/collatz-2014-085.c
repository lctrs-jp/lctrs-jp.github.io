#include <stdio.h>
#include <string.h>
int main (void)
{
	int n, i, j, k;
	printf("２以上３*2^53以下の整数をを入力");
	scanf("%d",&n);
	i = n;
	while(i != 1){
		if(i%2 == 0){
			i = i/2;
		}
		else{
			i = i * 3 + 1;
		}
		printf("%d ->",i);
	}
	return 0;
}
