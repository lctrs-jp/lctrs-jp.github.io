//テキストファイルのコピー
//2014.11.27


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *source, *dest;
  char ch;

  //引数の数のチェック
  if(argc != 3) {
    printf("Usage: ./%s source_file dest_file\n", argv[0]);
    exit(1);
  }

  //コピー元ファイルのオープンとチェック
  source = fopen(argv[1], "r");
  if(source == NULL) {
    printf("Error: source file doesn't exist.\n");
    exit(1);
  }

  //コピー先ファイルのオープンとチェック
  dest = fopen(argv[2], "r");
  if(dest != NULL) {
    printf("Error: dest file exists.\n");
    exit(1);
  }

  //コピー先ファイルのオープン
  dest = fopen(argv[2], "w");
  if(dest == NULL) {
    printf("Error: dest file open error.\n");
    exit(1);
  }


  //ファイルをコピーする
  while(!feof(source)) {
    ch = fgetc(source);
    if(ferror(source)) {
      printf("Error: source file read error.\n");
      exit(1);
    }

    if(!feof(source))
      fputc(ch, dest);
    if(ferror(dest)) {
      printf("Error: dest file write error.\n");
      exit(1);
    }
  }

  if(fclose(source) == EOF) {
    printf("Error: source file close error.");
    exit(1);
  }

  if(fclose(dest) == EOF) {
    printf("Error: dest file close error.");
    exit(1);
  }

  return 0;
}
