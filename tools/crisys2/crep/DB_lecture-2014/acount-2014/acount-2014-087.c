#include <stdio.h>
#include <string.h>
int main (void)
{
	char str[100], most[100];
	int i, j, k, count[50], len;
	printf("文字列をを入力してください（長さ100以下）");
	fgets(str,100,stdin);
	len = strlen(str)-1;
	
  		for(j = 0; j < len; j++){
    		if(97 <= str[j] && str[j] <= 122)
      			str[j] = str[j] - 32;//大文字に統一
  		}
	
	for(i = 0; i < len; i++){
		for(k = 65; k < 91; k++ ){
			if(str[i] == k){
				count[k]++;
			}
		}
	}
	//count[k]の内もっとも大きいものを探す
	int max = 0;
  	for(k = 65; k < 91; k++){
  		if(max <= count[k]){
  			max = count[k];
  		}
  	}
	
	printf("最頻出文字は ");
	for(k = 65; k < 91; k++){
		if(count[k] == max)
			printf("%c", k);
	}
	
	printf("\n");
	printf("出現回数は %d 回\n",max);
return 0;
}
