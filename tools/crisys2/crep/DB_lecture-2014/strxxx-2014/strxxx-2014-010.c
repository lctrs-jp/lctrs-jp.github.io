//課題２
//2014.10.23
//********* *****

#include <stdio.h>

void mystrcpy(char str1[], char str2[]);
void mystrcat(char str1[], char str2[]);
int mystrlen(char str[]);
int mystrcmp(char str1[], char str2[]);

int main()
{
  int cpy, cat, len1, len2;
  char str1[128], str2[128];

  printf("1つ目の文字列を入力してください:");
  gets(str1);
  printf("2つ目の文字列を入力してください:");
  gets(str2);

  //文字列の長さを確認する
  len1 = mystrlen(str1);
  printf("%s は %d 文字です\n", str1, len1);
  len2 = mystrlen(str2);
  printf("%s は %d 文字です\n", str2, len2);

  //文字列を比較する
  int cmp;
  cmp = mystrcmp(str1, str2);

  if(cmp < 0)
    printf("%s は %s より小さいです\n", str1, str2);
  else if(cmp > 0)
    printf("%s は %s より大きいです\n", str1, str2);
  else
    printf("文字列は等しいです\n");

  //十分なスペースがあれば、str2をstr1の末尾に連結する
  if(len1 + len2 < 128) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }
  //str2をstr1にコピーする
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char str1[], char str2[])
{
  int i = 0;

  while(str2[i] != '\0') {
    str1[i] = str2[i];
	i++;
  }

  str1[i] = '\0';
}

void mystrcat(char str1[], char str2[])
{
  int i = 0, j = 0;

  while(str1[i] != '\0')
    i++;

  while(str2[j] != '\0')
    str1[i++] = str2[j++];
}

int mystrlen(char str[])
{
  int i = 0;

  while(str[i] != '\0')
      i++;

  return i;
}

int mystrcmp(char str1[], char str2[])
{
  int i = 0, cmp;
  while(str1[i] == str2[i]) {
    if(str1[i] == '\0')
      break;
    i++;
  }

  cmp = (int)(str1[i] - str2[i]);
  if(cmp < 0)
    cmp = -1;
  else if(cmp > 0)
    cmp = 1;
  else
    cmp = 0;

  return cmp;
}