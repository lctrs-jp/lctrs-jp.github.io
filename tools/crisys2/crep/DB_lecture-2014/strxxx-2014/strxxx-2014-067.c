#include <stdio.h>
#include <string.h>

void mystrcpy(char trg[80], char src[80]);
void mystrcat(char trg[80], char src[80]);
int mystrlen(char trg[80]);

int main(void)/* メインのプログラム */
{
  char trg[80], src[80];
  int i;

    printf("第1の文字列を入力してください： ");
    fgets(trg, 80, stdin);
    printf("第2の文字列を入力してください： ");
    fgets(src, 80, stdin);

    /* 関数mystrlen()を使用 */
    printf("%s は %d 文字の長さです\n", trg, mystrlen(trg));
    printf("%s は %d 文字の長さです\n", src, mystrlen(src));

    /* 関数strcmp()を使い文字列比較を行う */
    i = strcmp(trg, src);
    if (!i)
      printf("文字列は等しい\n");
    else if (i < 0)
      printf("%s は %s より小さい\n", trg, src);
    else
      printf("%s は %s より大きい\n", trg, src);

    /* 関数mystrcat()を使用 */
    if ((mystrlen(trg) + mystrlen(src)) < 80) {
      mystrcat(trg, src);
      printf("%s\n", trg);
    } 

    /* 関数mystrcpy()を使用 */
    mystrcpy(trg, src);
    printf("%s %s\n", trg, src);

    return 0;
}

    /* 関数mystrlen()の定義 */
int mystrlen(char trg[80])
{
  int j, k;
  k = 0;
  for (j = 0; trg[j]; j++)  
    k++ ;
  return k - 1;
}

    /* 関数mystrcat()の定義 */
void mystrcat(char trg[80], char src[80])
{
  int q;
  int l = mystrlen(trg);
  for (q = 0; src[q] != '\0'; q++ ) {
    trg[q + l] = src[q];
 }
  trg[q + l] = '\0';
  
}

    /* 関数mystrcpy()の定義 */
void mystrcpy(char trg[80], char src[80])
{
  int j;

  for (j = 0; src[j] != '\0'; j++){
    trg[j] = src[j];
  }
  trg[j] = '\0';

  return;
}
