#include <stdio.h>
#include <string.h>
int main (void)
{
	
	char al[5];
	printf("アルファベット大文字を入力してください(5文字以下)　：");
	fgets(al, 5, stdin); 
	int len = strlen(al)-1;
	int num[5], i;
	for(i=0;i<5;i++){
		num[i]=0;
	}

	for(i=0;al[i] != '\n' ;i++){
		num[i] = al[i] - 64;
	}

	for(i=0;i<5;i++){
	printf("%d",num[i]);
	}
	
	
	return 0;
}