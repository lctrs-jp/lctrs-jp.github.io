#include<string.h>
#include<stdio.h>

int mytstrcpy(char trg[], char src[]);
int mystrcat(char trg[], char src[]);
int mystrlen(char trg[]); 

char str1[80],str2[80];

int main(void)
{
  int i;
 
  printf("第1の文字列を入力してください: ");
  gets(str1);
  printf("第2の文字列を入力してください: ");
  gets(str2);  

  /* 文字列の長さを確認する */
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
  if ((mystrlen(str1) + mystrlen(str2)) < 80 ) {
    mystrcat(str1, str2);
    printf("\n");
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("%s %s\n", str1, str2);

  return 0;
}
/* strcpy()と同じ処理をする関数 */
int mystrcpy(char trg[], char src[])
{
  int i;

  for (i = 0; (src[i] || trg[i]); i++)
    trg[i] = src[i];
}

/* strcat()と同じ処理をする関数 */
int mystrcat(char trg[], char src[])
{
  printf(trg);
  printf(src);
}

/* strlen()と同じ処理をする関数 */
int mystrlen(char trg[])
{
  int i = 0;

  while (trg[i] != '\0'){
    i++;
  }
    
  return i;
}
