#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chr_cnt(char str[],char c); /* 文字列 str 中の文字 c の数を返す関数 */

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][3][40] = { /* 入力と正しい出力のペア*/
    {"abracadabra", "a", "5"},
    {"abracadabra", "b", "2"},
    {"abracadabra", "r", "2"},
    {"abracadabra", "A", "5"},
    {"Nagoya University", "n", "2"},
    {"", "a","0"},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  char c;
  int result, answer;

  i = 0;
  while (strcmp(test[i][0],"***end***")){
    c = test[i][1][0];
    answer = atoi(test[i][2]);
    result = chr_cnt(test[i][0],c);
    if (answer == result)
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %d\n",result);
      printf("  期待される結果  : %d\n",answer);
    }
    i++;
  }

  return 0;
}

/* 以下の関数を変更する */
int chr_cnt(char str[],char c)
// 文字列 str 中の文字 c の数を返す関数
// 大文字と小文字は区別しない
{
  int i, count;

  count = 0;
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == c)
      count++;
  }

  return count;
}

