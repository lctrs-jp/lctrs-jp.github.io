#include <string.h>
#include <stdio.h>


int mystrlen(char trg[]);  /* プロトタイプ */
void mystrcat(char trg[], char src[]);
void mystrcpy(char trg[], char src[]);


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


  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
  printf("%s は %s より大きい\n", str1, str2);


  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }


  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);


  return 0;
}


int mystrlen(char trg[])
{
  int i = 0;
  for(i = 0; trg[i] != '\0'; i++)
    ;
  return i;
}


void mystrcat(char trg[], char str[])
{
  int i;
  int len = mystrlen(trg);
  for(i = 0; str[i] != '\0'; i++) {
    trg[i + len] = str[i];
  }
  trg[i + len] = '\0';
}


void mystrcpy(char trg[], char str[])
{
  int i;
  for(i = 0; str[i] != '\0'; i++) {
    trg[i] = str[i];
  }
  trg[i] = '\0';
}
