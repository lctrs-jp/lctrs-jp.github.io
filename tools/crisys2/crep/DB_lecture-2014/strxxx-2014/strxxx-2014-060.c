#include <string.h>
#include <stdio.h>

int mystrlen(char str[]);
int mystrcat(char str[], char src[], int a, int b);
int mystrcpy(char trg[], char src[]);

int main(void)
{
  char str1[80], str2[80];
  int i, c1, c2;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /* 文字の長さを確認する */
  c1 = mystrlen(str1);
  c2 = mystrlen(str2);

  printf("%s は %d 文字の長さです\n", str1, c1);
  printf("%s は %d 文字の長さです\n", str2, c2);

  /* str1をstr2の後ろに連結する */
  if((c1 + c2) < 80){
    mystrcat(str1, str2, c1, c2);
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

  for (i = 0; str[i] != '\0' ; i++){}

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
  for(i = 0; i < 80; i++)
    trg[i] = src[i];

  return 0;
}
