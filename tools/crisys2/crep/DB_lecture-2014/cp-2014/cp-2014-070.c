#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
  FILE *file1, *file2;
  char source;
  char cat1[100], cat2[100]; 
  /* コマンドラインのファイル数が正しいか調べる */
  if(argc != 3){
      printf("指定されたファイルの数が正しくありません。\nコピー元ファイルとコピー先ファイルの2つを指定してください。\n");
      exit(1);
    }
  /* コピー元ファイルが存在することを調べる */
  file1 = fopen(argv[1], "rb");
  if(file1 == NULL){
    printf("コピー元ファイルが正しくありません。\n存在するファイルを指定してください。\n");
    exit(1);
  }
  /* コピー先ファイルが存在しないことを調べる */
  file2 = fopen(argv[2], "rb");
  if(file2 != NULL){
    printf("コピー先ファイルが正しくありません。\n存在しないファイルを指定してください。\n");
    exit(1);
  }
  file2 = fopen(argv[2], "wb");
  while(!feof(file1)){
    source = fgetc(file1);
    if(ferror(file1)){
      printf("コピー元ファイルにてエラーが発生しました。");
      exit(1);
    }
    if(!feof(file1))
      fputc(source, file2);
    if(ferror(file2)){
      printf("コピー先ファイルにてエラーが発生しました。");
      exit(1);
    }
  }
  if(fclose(file1) == EOF){
    printf("コピー元ファイルを閉じる際にエラーが発生しました。");
    exit(1);
  }
  if(fclose(file2) == EOF){
    printf("コピー先ファイルを閉じる際にエラーが発生しました。");
    exit(1);
  }
  printf("正常にコピーが終了しました。\n");
  return 0;
}
