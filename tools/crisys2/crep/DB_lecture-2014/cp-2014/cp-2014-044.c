#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *ab, *fp;
  char ch;
  /* コピー元のファイルを開く*/

  if((ab = fopen(argv[1],"r")) == NULL){
    printf("コピー元のファイルを開くことはできません");
    exit(1);
  }


  /* 読み込み用テキストファイルを作成する*/

  if((fp = fopen(argv[2],"r")) != NULL){
    printf("ファイルを作成することができません\n");
    exit(1);
  }

  
  for(;;){
    ch = fgetc(ab);
    if(ch == EOF)
      break;
    fputc(ch, fp);
      }
}
