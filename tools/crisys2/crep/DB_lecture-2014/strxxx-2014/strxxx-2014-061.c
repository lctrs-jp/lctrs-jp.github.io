#include <stdio.h>
#include <string.h>

void mystrcpy(char t[], char s[]);
void mystrcat(char t[], char s[]);
int mystrlen(char t[]);

int main(void)
{
  char s1[100], s2[100];
  int i;

  printf("第一の文字列を入力してください: ");
  gets(s1);
  printf("第二の文字列を入力してください: ");
  gets(s2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", s1, mystrlen(s1));
  printf("%s は %d 文字の長さです\n", s2, mystrlen(s2));

  /* 文字列を比較する */
  i = strcmp(s1, s2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", s1, s2);
  else
    printf("%s は %s より大きい\n", s1, s2);

  /* 十分なスペースがあれば、s2をs1の最後に連結する */
  if ((mystrlen(s1) + mystrlen(s2)) < 100){
    mystrcat(s1, s2);
    printf("%s\n", s1);
  }

  /* s2をs1にコピーする */
  mystrcpy(s1, s2);
  printf("%s %s\n", s1, s2);

  return 0;
}



void mystrcpy(char t[], char s[])
{
  int i = 0;
  while (s[i] != '\0'){
    t[i] = s[i];
    i++;
  }
  t[i] = '\0';
}


void mystrcat(char t[], char s[])
{
  int i = 0, j = 0;
  while (t[i] != '\0'){
    i++;
  }
  while (s[j] != '\0'){
    t[i] = s[j];
    i++;
    j++;
  }
  t[i] = '\0';
}

int mystrlen(char t[])
{
  int i = 0;
  while (t[i] != '\0'){
    i++;
  }
  return i;
}
