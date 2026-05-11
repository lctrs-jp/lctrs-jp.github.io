#include <stdio.h>

int mystrlen(char trg[]);
void mystrcat(char trg[], char src[]);
void mystrcpy(char trg[], char src[]);

int main()
{
  char str1[80], str2[80];

  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第２の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1) );
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2) );

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

  while (trg[i] != '\0')
  {i++;
  }
  return i;
}

void mystrcat(char trg[], char src[])
{
  int n = 0, m = 0;

  while (trg[n] != '\0')
    {
    n++;
    }

  while (src[m] != '\0')
    {
    trg[n++] = src[m++];
    }
}

void mystrcpy(char trg[], char src[])
{
  int p;

  for (p = 0; p < 80; p++)
    trg[p] = src[p];
}
