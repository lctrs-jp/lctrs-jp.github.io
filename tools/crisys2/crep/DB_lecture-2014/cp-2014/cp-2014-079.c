/* ファイルをコピーする */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char str[128];

  /* 起動時引数の数が適切かどうか確認する */
  if (argc < 3) {
    printf("使用法: ＜プログラム名＞ ＜コピー元＞ ＜コピー先＞\n");
    exit(1);
  }

  /* コピー元ファイルを開く */
  if ((from = fopen(argv[1], "r")) == NULL) {
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  /* コピー先ファイルを開く */
  if ((to = fopen(argv[2], "w")) == NULL) {
    printf("コピー先ファイルを開くことができません\n");
    exit(1);
  }

  /*ファイルをコピーする */
  while (!feof(from)) {
    fgets(str, 127, from);
    if (ferror(from)) {
      printf("入力エラー\n");
      break;
    }
    if (!feof(from))
      fputs(str, to);
    if (ferror(to)) {
      printf("出力エラー\n");
      break;
    }
  }

  if (fclose(from) == EOF) {
    printf("コピー元ファイルを閉じる際にエラー\n");
    exit(1);
  }

  if (fclose(to) == EOF) {
    printf("コピー先ファイルを閉じる際にエラー\n");
    exit(1);
  }

  return 0;
}
