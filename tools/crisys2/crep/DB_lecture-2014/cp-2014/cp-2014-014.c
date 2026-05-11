#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp, *cpy;
  char hc, ch;

  if( argc != 3){
    printf("ファイルの指定がありません\n");
    exit(1);
  }

  if((fp = fopen(argv[1], "r")) == NULL){
    printf("コピー元のファイルがありません\n");
    exit(1);
  }
  /*コピー先のファイルがあるか確認する*/
  if(cpy = fopen(argv[2], "r")) {
    printf("コピー先のファイルが既に存在しています\n");
    exit(1);
    }

  if((cpy = fopen(argv[2], "w")) == NULL){
    printf("コピー先のファイルが開けません\n");
    exit(1);
  }
  
  /*コピーする*/
  while((ch = fgetc(fp)) != EOF)
    fputc(ch, cpy);
  
  fclose(fp);
  fclose(cpy);

  return 0;
}
