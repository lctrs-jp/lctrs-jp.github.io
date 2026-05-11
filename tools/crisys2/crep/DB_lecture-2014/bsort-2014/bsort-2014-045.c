#include <stdio.h>

int main(void){
	int i, j, k, l, m, n[100];
	
	printf("数をいくつ入力しますか？：");
	scanf("%d", &i);
	
	printf("数を%d個入力してください。\n", i);
	for(j = 1;j <= i; j++){
		printf("%d番目：", j);
		scanf("%d", &n[j - 1]);
	}
	
	for(m = 0; m < i; m++) printf("%d ", n[m]);
	printf("\n");
	
	for (j = 1; j < i; j++){
		for (k = i - 1; k >= j; k--) {
			if (n[k - 1] > n[k]) {
				l = n[k - 1];
				n[k - 1] = n[k];
				n[k] = l;
				for(m = 0; m < i; m++) printf("%d ", n[m]);
				printf("\n");
			}
		}
	}
	
	return 0;
}
