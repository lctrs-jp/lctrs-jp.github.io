#include <stdio.h>

int main() {
  char str[101];//100文字までとする
  printf("文字列を入力せよ : ");
  fgets(str,101,stdin); 
  //各文字の個数を調べるための変数定義
  int i;
  int count[27];//アルファベット27文字分の個数を格納する配列
  for(i=0;i<27;i++) { count[i]=0; }
  //各模試の個数を調べる
  for(i=0;str[i]!='\0';i++){
    if ('a'<=str[i] && str[i]<='z'){
      count[str[i]-'a']++;
    }
    if ('A'<=str[i] && str[i]<='Z'){
      count[str[i]-'A']++;
    }
  }
  //最頻出文字の文字数はいくつであるか調べる。
  int mostwordN=0;
  for(i=0;i<27;i++){
    if (mostwordN<=count[i]) {
      mostwordN=count[i];
    }
  }
  //最頻出文字文字数と文字数が一致する文字を表示
  printf("最頻出の文字は以下の通りです\n");
  for (i=0;i<27;i++){
    if (count[i]==mostwordN) {
      printf("文字 : %c(%c) … 文字数 : %d\n",(char)(i+'a'),(char)(i+'A'),count[i]);
    }
  }
  return 0;
}

