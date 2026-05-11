#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  /* コマンドライン引数の数が正しいかどうか確認する */
  if (argc != 3) {
    printf(" 使用法: <プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }

  /* コピー元ファイルを開く際のメッセージ */
  if ((from = fopen(argv[1], "r")) == NULL) {
    printf("コピー元ファイルが存在しません\n");
    exit(1);
  }
 
  /* コピー先ファイルを開く際のメッセージ */
  if ((to = fopen(argv[2], "r")) != NULL) {
    printf("コピー先ファイルが既に存在しています\n");
    exit(1);
  }
  if ((to = fopen(argv[2], "w")) == NULL) {
    printf("コピー先ファイルを開くことができません\n");
    exit(1);
  }

  /* ファイルをコピーする */
  while ((ch = fgetc(from)) != EOF) {
    fputc(ch, to);
  }
  fclose(from);
  fclose(to);

  return 0;
}
