#include<string.h>
#include<stdio.h>

/*ユーザー定義関数のプロトタイプ宣言*/
int mystrlen(char x[]);
void mystrcat(char x[], char y[]);
void mystrcpy(char x[], char y[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください: ");
  gets(str1);
  printf("第二の文字列を入力してください: ");
  gets(str2);

  /*文字列の長さを確認する*/
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /*文字列を比較する*/
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if ((mystrlen(str1) + mystrlen(str2)) < 80){
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  /* str2をstr1にコピーする*/
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}


/*文字列の長さを調べる関数*/
int mystrlen(char x[])
{
  int i;
  for (i = 0; i < 80; i++){
    if (x[i] == '\0')
      break;
  }
  return i;
}

/*文字列を連結する関数*/
void mystrcat(char x[], char y[])
{
  int i, j, k;
  i = mystrlen(x);
  j = mystrlen(y);
  for (k = 0; k < j + 1; k++){
    x[i+k] = y[k];
  }
  return;
}

/*文字列をコピーする関数*/
void mystrcpy(char x[], char y[])
{
  int i,j = mystrlen(y);
  for (i = 0; i < j +1; i++){
    x[i] = y[i];
  }
  return;
}
