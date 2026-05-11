#include <stdio.h>

/* mystrcpy()の作成 */
void mystrcpy(char trg[], char src[])
{
  int i;
  for( i = 0; src[i] !='\0'; i++ ) {
    trg[i] = src[i];
  }
  trg[i] ='\0';
}

/* mystrlen()の作成 */
int mystrlen(char str[])
{
  int i = 0;
  for( i = 0; str[i] !='\0'; i++ );
  return i;
}

/* mystrcat()の作成 */
void mystrcat(char trg[], char src[])
{
  int i;
  int len = mystrlen( trg );
  for( i = 0; src[i] !='\0'; i++ ) {
    trg[ i + len ] = src[i];
  }
  trg[ i + len ] = '\0';
}

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第１の文字列を入力してください: ");
  gets(str1);
  printf("第２の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((mystrlen(str1) + mystrlen(str2)) < 80) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}
 
