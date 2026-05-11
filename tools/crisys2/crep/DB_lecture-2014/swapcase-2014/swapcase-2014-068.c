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
  int i,j;
  char trg[40];
  i = 0;
  j = 0;
  for(j = 0; j < 40; j++)
    trg[j] = 0;
  for (i = 0; i < 40; i++){
    if (str[i] > 64 && str[i] < 91)
      trg[i] = str[i] + 32;
    
    else if(str[i] > 96 && str[i] < 123)
      trg[i] = str[i] - 32;
   
    else 
      trg[i] = str[i];
  }
  for(i = 0; i < 40; i++)
    str[i] = trg[i];
  return;
}
