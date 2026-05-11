#include <stdio.h>

void mystrcpy(char str1[80], char str2[80]);
void mystrcat(char str1[80], char str2[80]);
int mystrlen(char str1[80]);

int main()
{
  char str1[80], str2[80];

  printf("第1の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((strlen(str1) + strlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s\n", str1);

  return 0;
}


void mystrcpy(char str1[80], char str2[80])
{
  int i;
  for (i = 0; i < 80; i++)
    str1[i] = str2[i];
  return;
}


void mystrcat(char str1[80], char str2[80])
{
  int j;
  int length = mystrlen ( str1 );

  for ( j = 0; str2[j] != '\0'; j++ ) {
    str1[ j + length ] = str2 [j] ;
  }
  str1[ j + length] = '\0';

  return;
}


int mystrlen(char str1[80])
{
  int k;
  while(str1[k] != '\0') {
    k++;
  }
  return k;
}
