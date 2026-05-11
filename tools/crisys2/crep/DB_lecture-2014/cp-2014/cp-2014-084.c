#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;


 if((from = fopen(argv[1], "rb")) == NULL) {
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  if((to = fopen(argv[2], "rb")) != NULL) {
    printf("コピー先ファイルが既に存在します\n");
    exit(1);
  }

  if((to = fopen(argv[2], "wb")) == NULL) {
    printf("コピー先ファイルを開くことができません\n");
    exit(1);
  }

  while (!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("コピー元ファイルの読み込みエラー\n");
      exit(1);
    }
      if(!feof(from))
	fputc(ch, to);
      if(ferror(to)) {
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


