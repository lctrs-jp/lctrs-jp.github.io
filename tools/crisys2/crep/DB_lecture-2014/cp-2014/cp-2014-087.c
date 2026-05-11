//コマンドライン引数の数が正しいかどうか確認する
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *f, *t;
  char c;

  //コマンドライン引数の数が正しいかどうか確認する
  if (argc < 3){
    printf("使用法: <プログラム名> <コピー元> <コピー先→>\n");
    exit(1);
  }

  //コピー元ファイルを開く
  if((f = fopen(argv[1], "r")) == NULL){
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  //コピー先ファイルを開く
  if((t = fopen(argv[2], "r")) != NULL){
    printf("コピー先ファイルがすでに存在しています\n");
    exit(1);
  }
  else
    t = fopen(argv[2], "w");
  //ファイルをコピーする
  while ((c = fgetc(f)) != EOF){
    fputc(c, t);
  }
  fclose(f);
  fclose(t);

  return 0;
}
