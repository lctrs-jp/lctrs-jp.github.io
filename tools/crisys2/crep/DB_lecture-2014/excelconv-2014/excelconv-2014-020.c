#include <stdio.h>
#include <string.h>
#include <math.h>

//再帰呼び出しを使う
//コマンドラインから引数を取得
int main(){
  int x=0, i, j, k,l,m;  /* xは変換結果を格納，jは文字数を格納*/
  char num, e[5];  /* numは各文字を変換，eは入力文字列を格納 */

  /* 配列の初期化 */
  for ( k = 0; k < 5 ; k++ )
    e[k] = '\0';

  /* 文字列の取得->e */
  printf("変換する文字列(5桁まで)を入力してください: ");
  scanf("%s", e);

  /* 文字数の取得 */
  for ( j = 0; e[j] != '\0'; j++);

  /* 文字列の変換 */
  for ( i = 0; i < j ; i++ ) {
    l = pow (26,j-i-1);  /* 26^(文字数-1) */
    m = e[i]-'A'+1;  /* 各文字を26進数に変換 */
    num = m * l;
    x = x + num ;  /* これまで保持していた値に加算 */
  }

  printf("変換結果: %d\n", x);  /* 出力 */

  return 0;
}
