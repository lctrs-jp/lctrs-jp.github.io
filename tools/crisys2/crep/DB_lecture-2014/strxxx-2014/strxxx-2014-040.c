#include <stdio.h>
#include <string.h>

void mystrcpy(char sa[], char sb[]);//saにsbをコピー
void mystrcat(char sa[], char sb[]);//saの後ろにsbをコピー
int mystrlen(char s[]);//sの文字数を測定
int mystrcmp(char sa[], char sb[]);//saとsbを比較 sa>sb:1,sa=sb:0,sa<sb:-1

int main(){
	char s1[80], s2[80];
	
	printf("2文字列を入力してください。\n");
	printf("文字列１："); fgets(s1, 80, stdin); printf("\n");
	printf("文字列２："); fgets(s2, 80, stdin); printf("\n");

	printf("文字列１に %s ,文字列２に %s が代入されました。\n関数の実行を開始します......\n", s1, s2);

	printf("%s , %s の長さはそれぞれ %d , %d です。\n", s1, s2, mystrlen(s1), mystrlen(s2));

	switch (mystrcmp(s1, s2)){
	case 0:
		printf("２文字列は等しいです。\n"); break;
	case 1:
		printf("文字列１の方が大きいです。\n"); break;
	case -1:
		printf("文字列２の方が大きいです。\n"); break;
	}

	if (mystrlen(s1) + mystrlen(s2) <= 80){
		mystrcat(s1, s2);
		printf("文字列１＋文字列２： %s\n", s1);
	}

	mystrcpy(s1, s2);
	printf("文字列２をコピーした文字列１： %s\n", s1);

	printf("実行が完了しました。\n");

	return 0;
}

void mystrcpy(char sa[], char sb[]){
	int i;
	for (i = 0; sb[i] != 0; i++) sa[i] = sb[i];
	sa[i] = 0;
	return;
}

void mystrcat(char sa[], char sb[]){
	int i = 0, j = 0;
	while(sa[i] != 0) i++;
	for (; sb[j] != 0;j++) sa[i + j] =sb[j];
	sa[i + j] = 0;
	return;
}

int mystrlen(char s[]){
	int i = 0;
	while(s[i] != 0) i++;
	return i;
}

int mystrcmp(char sa[], char sb[]){
	int i = 0;
	while (sa[i] != 0 || sb[i] != 0){
		if (sa[i] > sb[i])return 1;
		if (sa[i] < sb[i])return -1;
		i++;
	}
	return 0;
}