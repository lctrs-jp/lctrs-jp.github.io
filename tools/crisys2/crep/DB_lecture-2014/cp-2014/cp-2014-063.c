#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  /*コピー元ファイルを開く*/
  if ((fp1 = fopen(argv[1], "r" )) == NULL){
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  /*コピー先ファイルを開く*/
  if ((fp2 = fopen(argv[2], "r" )) != NULL){
    printf("コピー先ファイルがすでに存在します\n");
    exit(1);
  }

  else
    fp2 = fopen(argv[2], "w");

  /*ファイルをコピーする*/
  while (!feof(fp1)){
    ch = fgetc(fp1);
    if(ferror(fp1)){
      printf("コピー元のファイルの読み込みエラー\n");
      exit(1);
    }
    if (!feof(fp1))
      fputc(ch, fp2);
    if (ferror(fp2)){
      printf("コピー先のファイルの読み込みエラー\n");
      exit(1);
    }
  }

  if (fclose(fp1) == EOF) {
    printf("コピー元ファイルを閉じる際のエラー\n");
    exit(1);
  }

  if (fclose(fp2) == EOF) {
    printf("コピー先ファイルを閉じる際のエラー\n");
    exit(1);
  }

  return 0;
}
