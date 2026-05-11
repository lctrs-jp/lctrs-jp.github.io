//第１回中間試験　問.3
//文字列中の最頻出のアルファベットとその出現回数を表示するプログラム
#include <stdio.h>

int main()
{
  int i, j;
  int temp = 0;			//最頻出文字の出現回数を保持する変数
  char str[101], cnt[26];	//cnt[]は各文字の出現回数を保持

  //配列の初期化を行う
  for (i = 0; i < 26; i++){
    cnt[i] = 0;
  }

  //文字列を入力してもらう
  printf("文字列を入力してください(長さ100以下): ");
  fgets(str, 101, stdin);

  //各アルファベットの出現回数を数えてcnt[]に入れる
  for (i = 0; str[i] != '\0'; i++){
    for (j = 0; j < 26; j++){
      if (str[i] == 'A' + j || str[i] == 'a' + j){
	cnt[j] = cnt[j] + 1;
      }
    }
  }

  //最頻出文字の出現回数を求める
  for (i = 0; i < 26; i++){
    if (temp < cnt[i]){
      temp = cnt[i];
    }
  }

  //最頻出文字を出力
  printf("最頻出文字は ");
  for (i = 0; i < 26; i++){
    if (temp != 0){		//アルファベットがなければ
      if (cnt[i] == temp){	//空白にする
	printf("%c ", 'a' + i);
      }
    }
  }
  printf("\n");

  printf("出現回数は %d回\n", temp);

  return 0;
}
