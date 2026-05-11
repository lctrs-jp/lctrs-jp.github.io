#include <stdio.h>

int main(void)
{
  int i, j, m[26], max;
  char str[101];

  /* 変数の初期化 */
  for (i = 0; i < 26; i++)
    m[i] = 0;
  
  /* 文字列を入力させる */
  printf("文字列を入力して下さい(長さ100以下)：");
  fgets(str, 100, stdin);
  
  /* a(A) から z(Z) の出現する回数を数える */
  for (i = 0; str[i]; i++) {
    for (j = 0; j < 26; j++) {
      if (str[i] == 'A' + j || str[i] == 'a' + j) // 大文字と小文字を区別しない
	m[j] = m[j] + 1;
    }
  }
  
  /* 最頻出の文字の回数を記録 */
  max = 0;
  for (i = 0; i < 26; i++) {
    if (m[i] > max)
      max = m[i];
  }
  
  printf("最頻出文字は ");
  /* 記録しておいた最頻出の文字の回数と出現回数が一致する文字を出力 */
  for (i = 0; i < 26; i++)
    if (max == m[i])
      printf("%c ", 'a' + i);
  
  printf("\n出現回数は %d回\n", max);
  
  return 0;
}
