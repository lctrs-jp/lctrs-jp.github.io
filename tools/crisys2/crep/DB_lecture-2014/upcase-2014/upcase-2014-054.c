#include <stdio.h>
#include <string.h>

void upcase(char str[]); /* 小文字を大文字に変換する関数 */

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][2][40] = { /* 入力と正しい出力のペア*/
    {"string", "STRING"},
    {"STRING", "STRING"},
    {"123aBc789", "123ABC789"},
    {"!@#$%^&*XyZ(){}", "!@#$%^&*XYZ(){}"},
    {"CamelStyle", "CAMELSTYLE"},
    {"snake_style", "SNAKE_STYLE"},
    {"全角ＡＢＣａｂｃ", "全角ＡＢＣａｂｃ"}, // 全角文字は変更しない
    {"", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  
  i = 0;
  while (strcmp(test[i][0],"***end***")){
    upcase(test[i][0]);
    if (!strcmp(test[i][0],test[i][1]))
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %s\n",test[i][0]);
      printf("  期待される結果  : %s\n",test[i][1]);
    }
    i++;
  }

  return 0;
}

/* 以下の関数を変更する */
void upcase(char str[])
// 文字列中の小文字を大文字に変換する関数
// ただし，変換するのは a から z までのアルファベットだけで
// それ以外の文字・記号は変更しない
{
  int i;

  /* 先頭から1文字ずつ順に処理 */
  for ( i = 0 ; str[i] != '\0' ; i++) {
    if( 'a' <= str[i] && str[i] <= 'z') {
      str[i] = str[i] - ('a'-'A'); /* 大文字と小文字の差分を除く */
    }  
  } 

  return;
}
