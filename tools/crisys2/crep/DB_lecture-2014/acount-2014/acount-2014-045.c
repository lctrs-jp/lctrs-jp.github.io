#include <stdio.h>

int main(void)
{
  int i,j=0,k,len,cnt[27];  /* cntには各文字の文字数を格納 */
  char str[101]; /* strには文字数を格納 */

  /* cntの初期化 */
  for ( i = 0; i < 27; i++ )
    cnt[i] = 0;
  
  printf("文字列を入力してください(長さ100以下): ");
  scanf("%c", str);

  for ( j = 0; str[j] != '\0'; j++ ) {
    if ( 'A' <= str[j] && str[j] <= 'Z' ) {
      cnt[str[j]-'A'] ++ ;
    }  
    else if ( 'a' <= str[j] && str[j] <= 'z' ) {
      cnt[str[j]-'a'] ++ ;
    }    
  }

  /* 最大の文字数を計算 */
  len = cnt[0];
  for ( k = 0; k < 27 ; k++) {
    if ( cnt[k] < cnt[k+1] ){
      len = cnt[k+1] + 1 ;
    }  
  }

  printf("出現回数は %d 回", len);

  return 0;
}
     
