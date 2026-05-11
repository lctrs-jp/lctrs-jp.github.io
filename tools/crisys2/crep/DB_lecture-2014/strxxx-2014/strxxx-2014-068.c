#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
 
void mystrcpy(char trg[], char src[])
{
  int a[80],b[80];
  int i;

  for (i = 1; i < 81; i++)
    a[i-1] = i;

  for (i = 0; i < 80; i++)
    b[i] = a[i];

  for (i = 0; i < 80; i++)
    printf("%d ", b[i]);
  
  
    }
void mystrcat(char trg[], char src[])
{
  int i;
  for( i=0; src[i] != '\0'; i++){
    trg[i] = src[i];
}
  trg[i] = '\0';
}
int mystrlen(char trg[])
{
  char a[80],b[80];
  int i;

  for (i = 0; i < 80; i++)
    a[i]=b[i];
      return i;
}
int main(void)
{
  char str1[80], str2[80];
  int i;
 
  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第２の文字列を入力してください: ");
  gets(str2);

  /* 文字の長さを確認する */
  printf("%s  %d 文字の長さです\n", str1, mystr1en(str1));
  printf("%s  %d 文字の長さです\n", str2, mystr1en(str2));

  /* 文字列を比較する */
  i = mystrcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は%sより大きい\n", str1, str2);

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
