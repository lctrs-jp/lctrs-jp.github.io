#include <stdio.h>
#include <string.h>

void cout(char trg[], char src[]);
/*入力された文字列に含まれる各数字の数を表示する関数*/
int main(void){
  int i, j, k;
  char trg[100], src[100];

  /*文字列の入力*/
  printf("文字を入力してください:");
  scanf("%s" , src );

  for( i = 0 ; i < 100 ; i++ ){
    if( src[i] = 0 )
      trg[i] = src[i];
      k = strlen(trg);
      printf("0は%d個含まれています\n", k);
      if( src[i] = 1 )
      trg[i] = src[i];
      k = strlen(trg);
      printf("1は%d個含まれています\n", k);
      if( src[i] = 2 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("2は%d個含まれています\n", k);
        if( src[i] = 3 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("3は%d個含まれています\n", k);
        if( src[i] = 4 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("4は%d個含まれています\n", k);
        if( src[i] = 5 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("5は%d個含まれています\n", k);
        if( src[i] = 6 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("6は%d個含まれています\n", k);
        if( src[i] = 7 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("7は%d個含まれています\n", k);
        if( src[i] = 8 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("8は%d個含まれています\n", k);
        if( src[i] = 9 )
        trg[i] = src[i];
        k = strlen(trg);
        printf("9は%d個含まれています\n", k);
  }
  return;
}
