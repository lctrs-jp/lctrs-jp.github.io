#include <stdio.h>
#include <string.h>

void downcase(char str[]);
void char_max(char str[]);
int char_count(char str[],char c);

int main(void)
{
  char str[100];

  printf("文字を入力してください(100文字まで)\n"); /* test! */
  fgets(str, 100, stdin);

  char_max(str);

  return 0;
}


void downcase(char str[])
/* 大文字から小文字に変換する関数 */
{
  int i;

  for (i = 0; i < strlen(str); i++){ /* 配列の要素を一つずつ取り出す */
    if (str[i] >= 'A' && str[i] <= 'Z'){ /* 大文字のアルファベットだと実行 */
      str[i] = str[i] + 32;		 /* 小文字に変換 */
    }
  }
  return;
}



int char_count(char str[],char c)
// 文字列 str 中の文字 c の数を返す関数
// 大文字と小文字は区別する
{
  int count = 0;
  int i;

  for (i = 0; i < strlen(str); i++){ /* 配列の要素を一つずつ検証 */
    if (str[i] == c){     /* 一致するか判定し、一致したらcountをインクリメント */
      count ++;
    }
  }
  return count;
}



void char_max(char str[])
/* str 中の最頻出文字を表示する関数 */
{
  int i, chr[26], max = 0;
  char most;
  
  downcase(str);		/* 扱いやすくするため大文字を小文字に変換 */

  for (i = 0; i < 26; i++){
    chr[i] = char_count(str, i + 'a'); /* aから順に出現する数をカウント */
    if (chr[i] > max){		    /* 最頻出の文字の個数を記録する */
      max = chr[i];
    }
  }

  if (max == 0){
    printf("文字列は空か、アルファベットが含まれていません！\n");
    return ;			/* 0回出現の文字が最頻出なら表示せず終了 */
  }

  for (i = 0; i < 26; i++){

    if (chr[i] == max){		/* 最頻出の文字の個数と一致する文字を表示 */
      printf("%c: %d回\n", i + 'a', max);
    }

  }
  return ;
}
