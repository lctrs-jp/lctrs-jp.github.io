#include <stdio.h>
#include <string.h>

void mystrcpy(char *str1, char *str2);
void mystrcat(char *str1, char *str2);
int  mystrlen(char *str);
//int  mystrcmp(char *str1, char *str2);

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
   /* str2をstr1の最後に連結する */
  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);
  return 0;
}


void mystrcpy(char *str1, char *str2)
{
  int i = 0;
  while(str2[i] != 0){
    str1[i] = str2[i];
    i++;
  }
  str1[i] = 0;
}

void mystrcat(char *str1, char *str2)
{
  int i = 0;
  int j = 0;
  while(str1[i] != 0)
    i++;
  while(str2[j] != 0)
    str1[i++] = str2[j++];
  str1[i] = 0;
}

int mystrlen(char *str)
{
  int n = 0;
  int i = 0;
  while(str[i++] != 0)
    n++;
  return n;
}
