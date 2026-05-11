#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *a, *b;
  char ch;

  if((a = fopen(argv[1], "r")) == NULL){
  printf("ファイルを開けません。\n");
  exit(1);
  }

  if((b = fopen(argv[2], "r")) != NULL){
    printf("ファイルが既に存在します。\n");
    exit(1);
  }

  if((b = fopen(argv[2], "w+")) == NULL){
    printf("ファイルを開けません。\n");
    exit(1);
  }

  printf("コピーの内容\n");
  while((ch = fgetc(a)) != EOF){
    putchar(ch);
    if(fputc(ch, b) == EOF){
      printf("コピーに失敗しました。\n");
      exit(1);
    }
  }

  fclose(b);

  if((b = fopen(argv[2], "r")) == NULL){
    printf("コピーの確認に失敗しました。\n");
    exit(1);
  }

  printf("コピー結果\n");
  while((ch = fgetc(b)) != EOF){
    putchar(ch);
  }
  fclose(a);
  fclose(b);

  return;
}
