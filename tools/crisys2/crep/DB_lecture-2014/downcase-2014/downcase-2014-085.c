#include <stdio.h>
#include <string.h>

void downcase(char str[]); // 大文字を小文字に変換する関数

/* main()関数は変更しない */
int main(void)
{
  char test[40];
  printf("変換する文字を入力します: ");
    fgets(test, 40, stdin);
  downcase(test);
  printf("%s", test);  
  return 0;
}

/* 以下の関数を変更する */
void downcase(char str[])
 
// 文字列中の大文字を小文字に変換する関数
// ただし，変換するのは A から Z までのアルファベットだけで
// それ以外の文字・記号は変更しない
{
  int k, l, m;
  for ( k = 0; str[k] != '\0' ; k++ ){
   l = str[k] - 'A';
  if (l >= 0){
    m = 'Z' - str[k];
    if(m >= 0)
      str[k] = str[k] + 32;
  }
  }
  return;
}
