#include <stdio.h>
#include <string.h>

int mystrlen(char trg[])

;void mystrcat(char trg[], const char src[])

;void mystrcpy(char trg[], char src[])

;int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /*文字列の長さを確認する*/
  i = strcmp(str1, str2);
  if(!i)
	printf("文字列は等しい\n");
  else if(i < 0)
	printf("%s は %s より小さい\n", str1, str2);
  else
	printf("%s は %s より大きい\n", str1, str2);

  /*十分なスペースがあれば、str1をstr2の最後に連結する*/
  if((mystrlen(str1) + mystrlen(str2)) < 80){
	mystrcat(str1, str2);
	printf("%s\n", str1);
  }

  /*str2をstr1にコピーする*/
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

int mystrlen(char trg[])
{
  int x = 0;
  for(x = 0; trg[x] != '\0'; x++)
	;

  return x;
}

void mystrcat(char trg[], const char src[])
{
  int x = 0;
  int y = mystrlen(trg);

  for(x = 0; src[x] != '\0'; x++){
	trg[x + y] = src[x];
  }
  trg[x + y] = '\0';

}

void mystrcpy(char trg[], char src[])
{
  int x;

  for(x = 0; x < 80; x++)
	trg[x] = src[x];
}
