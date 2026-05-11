#include<stdio.h>
#include<string.h>

int main(void)
{
	int i,j;
	int a;
	int count=0;
	char s[256];
	
	printf("数字列を入力してください(長さ100以下) : ");
	scanf("%s", s);

	for(i=0;i<s[i];i++){
		if(i > 100){
		 printf("長さ100以下で入力してください\n");
	 	printf("プログラムを終了します\n");
	 	return 0;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<s[j];j++){
			if((int)s[j] == i + 48){
				a++;
			}
		}
		printf("%d は %d 個含まれています\n", i, a);
		a=0;
	}
	
	return 0;
}