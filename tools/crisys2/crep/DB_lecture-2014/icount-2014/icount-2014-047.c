#include <stdio.h>
#include <string.h>
int main (void)
{
	int kosuu[10]={0,0,0,0,0,0,0,0,0,0}, k=0, l, len;
	//kは文字列の何番目かを保持
	//lは数える対象の数字, 
	char number[101];

	printf("数字列を入力してください(長さ100以下)　：");
	fgets(number, 100, stdin);
	printf("\n"); 
	len = strlen(number)-1;

	for(l=0; l<10; l++){//lが
		for(k=0; k<len; k++){//k番目に
			if(l==number[k]-48) //あったら
				kosuu[l]++;//kosuu[l]にプラス1
		}
	}
	

	for(l=0; l<10; l++){
		printf("%d は %d個含まれています.\n",l ,kosuu[l]);
	}
	return 0;
}