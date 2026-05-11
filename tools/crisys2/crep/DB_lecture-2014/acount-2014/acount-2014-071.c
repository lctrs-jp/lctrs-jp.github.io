#include <stdio.h>
#include <string.h>

void downcase(char str[]); /* 小文字を大文字に変換する関数 */
void most(char str[]);

int main(void){
	char gt[100];
	printf("文字列を入力して下さい(長さ100以下) :");
	fgets(gt, 100, stdin);
	downcase(gt);
	most(gt);
	return;
}

void downcase(char str[]){
	int i;
	for(i = 0; strlen(str) - i; i++){
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
	}
}

void most(char str[]){
	int i, j, k, l = 0, m, max = 0;
	char most[26];
	for(m = 0; m <= 25; m++) most[m] = 0;//most初期化
	most[0] = 'a';
	for(j = 0; j <= 25; j++){
		k = 0;//k:jで指定したアルファベットの個数
		for(i = 0; strlen(str) - i; i++){
			if(str[i] - (char)j == 'a') k++;
		}
		if(k == max){
			most[l] = 'a' + j;
			l++;
		}//k=maxならmost文字列にj追加
		else if(k > max){
			for(m = 0; m <= 25; m++) most[m] = 0;
			max = k;
			l = 0;
			most[l] = 'a' + j;
			l++;
		}//k>maxならmost文字列をリセットしj追加
	}//j:アルファベット 0=a, 1=b,...,25=z
	most[l] = '\0';
	printf("最頻出文字は %s\n", most);
	printf("出現回数は %d回\n", max);
}
