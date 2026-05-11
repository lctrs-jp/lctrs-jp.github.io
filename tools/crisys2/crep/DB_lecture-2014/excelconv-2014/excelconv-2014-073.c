#include <stdio.h>

int main(int argc, char *argv[])
{
  int j, plus;

  plus = 0;//初期化
  for(j = 0; *(argv[1]+j) != '\0'  && *(argv[1]+j) >= 'A' && *(argv[1]+j) <= 'Z' ; j++){//大文字の範囲でループを繰り返す
    if(j >= 5){//６文字以上ならループを終わる
      printf("エラー\n");
      break;
    }
    
    plus = plus*26 + *(argv[1]+j) - 64;
  }
  printf("%d\n",plus);

  return 0;
}
