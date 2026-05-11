#include <string.h>
#include <stdio.h>
/*-------------------------------------*/
//ユーザー関数の指定
void mystrcpy(char trg[], char src[])
{
	int i;
	for (i = 0; src[i] != '\0'; i++){
			trg [i] = src[i];
	}
	trg [i] = '\0';
}


void mystrcat(char trg[], char src[])
{
	int i, j;//iでtrgの\nを見つける
	for(i = 0; trg[i] != '\0'; i++){		
	}//

	for(j = 0; src[j] != '\0'; j++, i++){
		trg[i] = src[j];
	}
	trg[i] = '\0';
}


int mystrlen(char trg[])
{ 
	int i;
	for(i = 0; trg[i] != '\0'; i++){
	}
	return i;
}


/*--------------------------------*/
int main (void)
{
	char str1[80], str2[80];
	int i;
	

	printf("第一の文字列を入力して下さい: ");
	fgets(str1, 80, stdin);
	strtok(str1,"\n");
	printf("第二の文字列を入力して下さい: ");
	fgets(str2, 80, stdin);
	strtok(str2,"\n");

	//文字列の長さを確認する
	printf("%s は %d 文字の長さです\n", str1, mystrlen(str1) );
	printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

	//文字列を比較する
	i = strcmp(str1, str2);
	if (!i)
		printf("文字列は等しい\n");
	else if (i < 0)
		printf("%s は %s より小さい\n", str1, str2);
	else
		printf("%s は %s より大きい\n", str1, str2);
	
	//十分なスペースがある場合str2をstr1の最後に連結させる
	if(mystrlen(str1) + mystrlen(str2) < 80){
		mystrcat(str1, str2);
		printf("%s\n", str1);
	}

	//str2をstr1にコピー
	mystrcpy(str1, str2);
	printf("%s %s\n", str1, str2);

	return 0;
}