#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  FILE *from,*to;
  char ch;

  if (argc != 3){
    printf("使用法: <プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }

  if ((from = fopen(argv[1], "rb")) == NULL){
    printf("コピー元のファイルは存在しません。\n");
    if((from = fopen(argv[2], "rb")) == NULL)
      printf("コピー先のファイルは存在しません。\n");
    else
      printf("コピー先のファイルは存在します。\n");
    exit(1);
  }


  if ((to = fopen(argv[2], "wb")) == NULL){
    printf("コピー先のファイルは存在しません。\n");
    exit(1);
  }

  while (!feof(from)){
    ch = fgetc(from);
    if (ferror(from)){
      printf("コピー元のファイルの読み込みエラー。\n");
      exit(1);
    }
    if (!feof(from))
      fputc(ch, to);
    if (ferror(to)){
      printf("コピー先のファイルの書き込みエラー。\n");
      exit(1);
    }
  }

  if (fclose(from) == EOF) {
    printf("コピー元のファイルを閉じる際のエラー。\n");
    exit(1);
  }

  if (fclose(to) == EOF) {
    printf("コピー先のファイルを閉じる際のエラー。\n");
    exit(1);
  }

  return 0;
}
