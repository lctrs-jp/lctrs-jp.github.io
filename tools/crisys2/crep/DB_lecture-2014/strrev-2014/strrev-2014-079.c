#include <stdio.h>
#include <string.h>

void reverse(char trg[],char src[]); /* 文字列を逆順にする関数 */

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][2][40] = { /* 入力と正しい出力のペア*/
    {"STRING", "GNIRTS"},
    {"string", "gnirts"},
    {"abc", "cba"},
    {"a", "a"},
    {"bb", "bb"},
    {"level","level"},
    {"akasaka","akasaka"},
    {"", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  char output[40];

  i = 0;
  while (strcmp(test[i][0],"***end***")){
    reverse(output,test[i][0]);
    if (!strcmp(output,test[i][1]))
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %s\n",output);
      printf("  期待される結果  : %s\n",test[i][1]);
    }
    i++;
  }

  return 0;
}

/* 以下の関数を変更する */
void reverse(char trg[],char src[])
// src の内容を逆順にしたものが trg に入る
{
  int i, len;
  len =  strlen(src[]);
  for(i = 0; src[i] != '0'; i++){
    trg[i] = len - src[i];
  }
  return 0;
}
