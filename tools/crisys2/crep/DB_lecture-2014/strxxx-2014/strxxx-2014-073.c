#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);
int mystrcmp(char trg[], char src[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください：");
  gets(str1);
  printf("第2の文字列を入力してください：");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /* 文字列を比較する */
  i = mystrcmp(str1, str2);

  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する。*/
  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1,str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

/* 文字列を別の文字列にコピーする */
void mystrcpy(char trg[], char src[])
{
  int i;
  for (i=0; i < 80; i++)
    trg[i] = src[i];
}

/* 文字列に別の文字列を加える */
void mystrcat(char trg[], char src[])
{
  int i,j,k;
  j = mystrlen(src);
  k = mystrlen(trg);

  for (i=0; i < j; i++)
    trg[k + i] = src[i];

  trg[j + k] = 0;
}

/* 文字列の長さを返す */
int mystrlen(char trg[])
{
  int i;
  for (i=0; i < 80; i++) 
    if (trg[i] == 0)
      return i;
}

/* 文字列を比較し、数字を返す */
int mystrcmp(char trg[], char src[])
{
  int i;
  for (i=0; i < 80; i++) {
    if (trg[i] == src[i])
      continue;
    break;
  }

  return trg[i] - src[i];
}
