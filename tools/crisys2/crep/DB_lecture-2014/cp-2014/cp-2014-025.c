#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char str[128];

  /* コマンドラインに指定された引数が正しいかどうか調べる */
  if (argc != 3){
    printf("使用法: <プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }

  /* コピー元のファイルを開く */
  if ((from = fopen(argv[1], "r")) == NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);
  }

  /* コピー先のファイルが存在しないことを確認 */
  if ((to = fopen(argv[2], "r")) != NULL){
    printf("コピー先のファイルが既に存在します\n");
    exit(1);
  }

  /* コピー先のファイルを開く */
  if ((to = fopen(argv[2], "w")) == NULL){
    printf("コピー先のファイルを開くことができません\n");
    exit(1);
  }

  /* ファイルをコピーする */
  while (!feof(from)){
      fgets(str, 127, from);
    if (ferror(from)){
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
    printf("コピー元のファイルを閉じる際にエラー\n");
    exit(1);
  }

  if (fclose(to) == EOF) {
    printf("コピー先のファイルを閉じる際にエラー\n");
    exit(1);
  }

  return 0;
}
