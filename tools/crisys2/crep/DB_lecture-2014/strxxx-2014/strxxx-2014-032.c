#include <string.h>
#include <stdio.h>

int mystrcpy(char trg[], char src[]);
int mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);

char str1[80], str2[80];

int main(void)
{
  int i, m, n;

  printf("第1の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は", str1);
  m = mystrlen(str1);
  printf("%d 文字の長さです\n", m);
  printf("%s は", str2);
  n = mystrlen(str2);
  printf("%d 文字の長さです\n", n);

  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else 
    printf("%s は %s より大きい\n", str1, str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((m + n) < 80)
    mystrcat(str1, str2);
  printf("\n");

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}


int mystrcpy(char trg[], char src[])
{
  int i;

  for (i = 0; (src[i] || trg[i]); i++)
    trg[i] = src[i];
  

}


int mystrcat(char trg[], char src[])
{
  printf(trg);
  printf(src);


}


int mystrlen(char trg[])
{
  int i, max, t[80];

  for (i = 0; trg[i]; i++)
    t[i] = i + 1;

  max = 0;
  for (i = 0; trg[i]; i++)  {
      if (t[i] > max)
        max = t[i];
    }

  return max;
}
