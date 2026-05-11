#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1;
  FILE *fp2;
  char ch;

  //起動時引数の数が正しいか確かめる
  if(argc != 3) {
    printf("使い方が違います");
    exit(1);
  }

  //コピー元ファイルを開く
  if((fp1 = fopen(argv[1], "r")) == NULL) {
      printf("コピー元ファイルを開く際にエラーが発生しました\n");
      printf("コピー元ファイルが存在しない可能性があります\n");
      exit(1);
  }

  //コピー先ファイルが存在していないか確かめる
  if((fp2 = fopen(argv[2], "r")) != NULL) {
      printf("コピー先ファイルが既に存在しています\n");
      exit(1);
  }

  //コピー先ファイルを作成して開く
  if((fp2 = fopen(argv[2], "w")) == NULL) {
      printf("コピー先ファイルを作成し開く際にエラーが発生しました\n");
      exit(1);
  }

  //ファイルの内容をコピーする
  while(!feof(fp1)) {
    ch = fgetc(fp1);
    if(!feof(fp1))
      fputc(ch, fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}
    
