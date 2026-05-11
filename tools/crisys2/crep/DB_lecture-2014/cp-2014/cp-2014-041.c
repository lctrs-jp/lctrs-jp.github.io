#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char ag1[80], ag2[80];//それぞれargv[1],[2]の文字列
	int i, c;
	for(i = 0; argv[1][i]; i++) ag1[i] = argv[1][i];
	ag1[i] = '\0';
	for(i = 0; argv[2][i]; i++) ag2[i] = argv[2][i];
	ag2[i] = '\0';
	
	FILE *fp1, *fp2;
	if((fp1 = fopen(ag1, "r")) == NULL){
		printf("1つ目のファイルのオープンに失敗しました。\n");
		exit(1);
	}//なきゃダメ
	if((fp2 = fopen(ag2, "r")) != NULL){
		printf("2つ目のファイルがすでに存在します。\n");
		exit(1);
	}//あったらダメ
	if((fp2 = fopen(ag2, "w")) == NULL){
		printf("2つ目のファイルのオープンに失敗しました。\n");
		exit(1);
	}//なきゃダメ
	
	while((c = fgetc(fp1)) != EOF) fputc(c, fp2);//fp1の文字を順次cに入れ、それをfp2に入れる
	
	fclose(fp1); fclose(fp2);//閉じる
	return 0;
}
