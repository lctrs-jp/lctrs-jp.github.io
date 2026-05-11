#include <stdio.h>
#include <string.h>

void reverse(char trg[], char src[]);
int main()
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

void reverse(char trg[], char src[]){
  int length=strlen(src);
  int i;
  for(i=0;i<length;i++){
    trg[i]=src[length-i-1];
  }
  trg[length]='\0';
  return;
}
