#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

  FILE *source, *dest;
  char p;

  /* コピー元のファイルを開く */
  /* コピー元ファイルが存在しない場合エラーを返す */
  if((source = fopen(argv[1], "r")) == NULL) {
    printf("Can't open file.(source)\n");
    exit(1);
  }

  dest = fopen(argv[2], "w");
  /* コピー先のファイルを開く */
  /* コピー先ファイルが既に存在する場合エラーを返す */
  // if((dest = fopen(argv[2], "w")) != NULL) {
  //  printf("File exists.(dest)\n");
  //  exit(1);
  //}

  /* コピー元ファイルをコピー先ファイルに書き込む */
  while( (p = fgetc(source)) != EOF )
    fputc(p,dest);

  /* ファイルのクローズ */
  fclose(source);
  fclose(dest);

  return 0;
}
