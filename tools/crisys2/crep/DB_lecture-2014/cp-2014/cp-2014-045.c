#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  //check argument
  if (argc != 3) {
    printf("使用方法: <プログラム> <コピー元> <コピー先>\n");
    exit(1);
  }

  //open source file
  if ((from = fopen(argv[1], "r")) == NULL) {
    printf("コピー元ファイルを開けません\n");
    exit(1);
  }

  //open target file
  if ((to = fopen(argv[2], "w")) == NULL) {
    printf("コピー先ファイルを開けません\n");
    exit(1);
  }

  //coppy date
  while (!feof(from)) {
    ch = fgetc(from);
    if (ferror(from)) {
      printf("コピー元ファイルの読み込みエラー\n");
      exit(1);
    }
    if (!feof(from))
      fputc(ch, to);
    if (ferror(to)) {
      printf("コピー先ファイルの書き込みエラー\n");
      exit(1);
    }
  }

  if (fclose(from) == EOF) {
    printf("コピー元ファイルを閉じる際のエラー\n");
    exit(1);
  }

  if (fclose(to) == EOF) {
    printf("コピー先ファイルを閉じる際のエラー\n");
    exit(1);
  }

  return 0;
}

