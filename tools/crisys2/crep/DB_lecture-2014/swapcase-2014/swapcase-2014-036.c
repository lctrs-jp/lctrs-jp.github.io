#include <stdio.h>
#include <string.h>

void swapcase(char str[]); /* 大文字と小文字を入れ替える関数 */

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][2][40] = { /* 入力と正しい出力のペア*/
    {"STRING", "string"},
    {"string", "STRING"},
    {"123aBc789", "123AbC789"},
    {"!@#$%^&*XyZ(){}", "!@#$%^&*xYz(){}"},
    {"CamelStyle", "cAMELsTYLE"},
    {"Japan", "jAPAN"},
    {"全角ＡＢＣａｂｃ", "全角ＡＢＣａｂｃ"}, // 全角文字は変更しない
    {"", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  
  i = 0;
  while (strcmp(test[i][0],"***end***")){
    swapcase(test[i][0]);
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
void swapcase(char str[])
// 文字列中の大文字を小文字に，小文字は大文字に変換する関数
// ただし，変換するのは a から z，AからZ までのアルファベットだけで
// それ以外の文字・記号は変更しない
{
  int a , len;
 
  len = strlen(str);

  for(a = 0; a < len; a++){

  //大文字を小文字にする
   if((str[a] >= 65) && (str[a] <= 90))
     str[a] = str[a] + 32;
 
  //小文字を大文字にする
   else
     if((str[a] >= 97) && (str[a] <= 122))
       str[a] = str[a] - 32;
  }

  return;
}
