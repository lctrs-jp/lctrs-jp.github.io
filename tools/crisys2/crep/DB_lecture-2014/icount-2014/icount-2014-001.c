#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TEN 10
#define GAP 48

/* string中の各数字の数を表示する */
void countNumber(char* string);

int main(void)
{
  char str[MAX];

  printf("数字列を入力してください(長さ%d以下) : ", MAX);
  scanf("%s", str);

  countNumber(str);

  return 0;
}

void countNumber(char* string)
{
  int i;
  int num[TEN];

  /* 初期化 */
  for(i=0; i<TEN; i++)
    num[i] = 0;

  /* カウント */
  for(i=0; string[i]!='\0'; i++)
    if('0' <= string[i] && string[i] <= '9')
      num[(int)string[i]-GAP]++;	// 文字コードから配列のインデックスを求める

  /* 表示 */
  for(i=0; i<TEN; i++)
    printf("%d は %d個含まれています.\n", i, num[i]);
}
