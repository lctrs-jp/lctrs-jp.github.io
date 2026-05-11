#include <stdio.h>
#include <string.h>
int main()
{
  int i,j;
  int num[10]; /* 数字個数 */
  int len; /* 入力された文字数 */
  char buf[101]; /* 入力文字列 */

  /* 数字個数を0に初期化 */
  memset( num, 0, sizeof( num ) );

  /* 文字列を入力する */
  printf("input number (1~100)");
  scanf("%s", buf );

  len = (int)strlen( buf );
 
  /* 個数を数える */
  for (i = 0; i < len; i++) {
    num[ buf[i] - '0' ]++;
  }

  /* グラフ表示 */
  for (i = 0; i < 10; i++) {
    printf("%d⇒ %d個", i, num[i] );
    for (j = 0; j < num[i]; j++) {
    }
    printf("\n");
  }
  return 0;
}
