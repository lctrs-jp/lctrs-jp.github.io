#include <stdio.h>

int main(void){
	char num[100];
	
	printf("数字列を入力してください(長さ100以下)：");
	fgets(num, 100, stdin);
	
	int app[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i, j;
	for(i = 0; num[i] != '\n'; i++){
		j = num[i] - '0';
		app[j]++;
	}
	
	int k;
	for(k = 0; k <= 9; k++){
		printf("%d は %d 個含まれています。\n", k, app[k]);
	}
	
	return 0;
}