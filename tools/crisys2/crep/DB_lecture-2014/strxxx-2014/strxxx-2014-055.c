#include <string.h>
#include <stdio.h>

//関数プロトタイプ宣言
int mystrlen(char trg[]);
void mystrcat(char trg[] , char src[]);
void mystrcpy(char trg[] , char src[]);


int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if (mystrlen(str1) + mystrlen(str2) < 80) {
  mystrcat(str1, str2);
  printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

//関数本体
int mystrlen(char trg[])
{ 
	int i;
	for(i=0;trg[i];i++)
	;
	
	return i;
}

void mystrcat(char trg[] , char src[] )
{ 
	int i,j;
	
	//trgの終わりを探す
	for(i=0;trg[i];i++)
	;
	
	//終わりを記録
	j=i;
	
	//trgの終わりから先にsrcをコピー
	for(i=0;src[i];){
		trg[j]=src[i];
		j++;
		i++;
	}
	
	//trgの最後に０を置き直す
	trg[j]=0;
	
	return;
}

void mystrcpy(char trg[] , char src[] )
{ 
	int i;
	for(i=0;i<80;i++){
		trg[i]=src[i];
	}
	
	return;
}
