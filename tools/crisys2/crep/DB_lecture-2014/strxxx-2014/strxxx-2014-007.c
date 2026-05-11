#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);

int main (void)
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください:");
  fgets(str1, 80, stdin);
  printf("第二の文字列を入力してください:");
  fgets(str2, 80, stdin);

  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str2, str1);

  if ((strlen(str1) + strlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

void mystrcpy(char trg[], char src[])
{
  int i;

  for (i = 0;trg[i] || src[i];i++)
    trg[i] = src[i];

}

void mystrcat(char trg[], char src[])
{
  int i, j;
  for (i = 0;trg[i];i++) ;

  for (j = 0;src[j];j++) trg[i++] = src[j];
}

int mystrlen(char trg[])
{
  int i;
  for (i = 0;trg[i];i++) ;

  return i - 1;
}
