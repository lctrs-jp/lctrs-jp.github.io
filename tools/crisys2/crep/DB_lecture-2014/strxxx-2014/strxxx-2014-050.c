#include <string.h>
#include <stdio.h>

void mystrcpy(char trg[], char src[]);

void mystrcat(char trg[], char src[]);

int mystrlen(char trg[]);


int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください: ");
  fgets(str1, 80, stdin);
  str1[mystrlen(str1) - 1] = '\0';//改行を防ぐ
  printf("第2の文字列を入力してください: ");
  fgets(str2, 80, stdin);
  str2[mystrlen(str2) - 1] = '\0';//改行を防ぐ
 
 /* 文字列の長さを確認する */
  printf("「%s」は%d文字の長さです。\n", str1, mystrlen(str1));
  printf("「%s」は%d文字の長さです。\n", str2, mystrlen(str2));

  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if(!i)
    printf("文字列は等しい\n");
  else if(i < 0)
    printf("「%s」は「%s」より小さい。\n", str1, str2);
  else
    printf("「%s」は「%s」より大きい。\n", str1, str2);
  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if((mystrlen(str1) + mystrlen(str2)) < 80)
    {
      mystrcat(str1, str2);
      printf("連結：%s\n", str1);
    }

  /* str2をstr1にコピーする */
  mystrcpy(str1 ,str2 );
  printf("コピー：%s\nコピー元：%s\n", str1, str2);

  return 0;
}

void mystrcpy(char trg[], char src[])
{
  int i;

  for(i = 0; i < 80; i++ )
    {
      trg[i] = src[i]; //コピー
    }
}


void mystrcat(char trg[], char src[])
{
  int i;
  int j;

  for( i = 0; i < 80; i++)
    if(!trg[i])//ヌル文字判定
      for( j = 0; i < 80; j++)//文字連結
	{
	  trg[i] = src[j];
	  i = i + 1;
	}
}


int mystrlen(char trg[])
{
  int i;
  int t;
  t = 0;

  for(i = 0; trg[i]; i++)
    {
      t = t + 1;//数え上げ
    }


  return t;
}
