#include <string.h>
#include <stdio.h>

int mystrlen(char trg[]);
int mystrcat(char trg[], char src[], int a, int b);
int mystrcpy(char trg[], char src[]);

int main(void)
{
  char str1[80], str2[80];
  int i, a1, a2;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  a1 = mystrlen(str1);
  a2 = mystrlen(str2);

  printf("第一の文字列の文字数は: %d\n", a1);
  printf("第二の文字列の文字数は: %d\n", a2);

  /* 十分なスペースがあれば、str1をstr2の最後に連結する */
  if ((a1 + a2) < 80) {
    mystrcat(str1, str2, a1, a2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);

  printf("%s %s\n", str1, str2);

  return 0;
}

int mystrlen(char str[])
  {
int i;

for(i = 0; str[i] != '\0'; i++){}

 return i;
}

int mystrcat(char trg[], char src[], int a, int b)
{
  int i, j;
  char str[80];

  for (i = 0; i < 80; i++)
    str[i] = trg[i];

  for (j = 0; j < (80 - a); j++)
    str[a + j] = src[j];

  mystrcpy(trg, str);

  return trg;
}

int mystrcpy(char trg[], char src[])
{
  int i;

  for (i = 0; i < 80; i++)
    trg[i] = src[i];

  return 0;
}
