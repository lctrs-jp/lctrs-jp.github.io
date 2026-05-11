#include <stdio.h>
#include <string.h>

int cal();

int main()
{
  int i;
  int test[][2][100] = { // 入力と正しい出力のペア
    {"abracadabra", "a"},
    {"AabaA", "a"},
    {"ABCabc", "abc"},
    {"abber", "b"}, 
    {"***end***", ""} //テストの終わり。このテストは実行されない
  };
  

  i = 0;
  while (strcmp(test[i][0],"***end***")){
    cal(test[i][0]);
    if (!strcmp(test[i][0],test[i][1]))
      printf("テスト&dは成功\n",i+1);
    else{
      printf("テスト%dは失敗\n",i+1);
      printf("作った関数の出力 %s\n",test[i][0]);
      printf("期待される結果   %s\n",test[i][1]);
    }
    i++;
  }
  return 0;
}






