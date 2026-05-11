#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[110];
  int cnt[30];
  int i, j, max = 0;

  printf("文字列を入力してください(長さ100以下):");
  fgets(str, 100, stdin);

  for(i = 0; i < 30; i++) //文字のカウント数を0に初期化
    cnt[i] = 0;
  
  for(j = 0; j <= 25; j++){
    for(i = 0; i < strlen(str); i++){
      //大文字の処理
      if(str[i] == 65 + j)
	cnt[j]++;
      //小文字の処理
      if(str[i] == 97 + j)
	cnt[j]++;
    }
  }
  //最頻出回数を求める
  for(i = 0; i < 30; i++){
    if(cnt[i] > max)
      max = cnt[i];
  }   

  //最頻出回数と出現回数が一致している文字を出力する
  printf("最頻出文字は ");
  for(i = 0; i < 30; i++){
    if(cnt[i] == max)
      printf("%c ", i + 97);
  }
  printf("\n出現回数は %d回\n", max);

  return 0;
}
   
