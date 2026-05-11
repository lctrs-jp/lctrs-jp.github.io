#include <stdio.h>
#include <stdlib.h>

void main(int argc, char*argv[])
{
  FILE *f1,*f2;
  char ch, *p;
  if((f1 = fopen(argv[1], "r")) == NULL){
    printf("読み込みファイルをオープンできません。\n");
    exit(1);
  }
  if((f2=fopen(argv[2],"w")) != NULL){
    printf("同じ名前のファイルが既に存在しています。別の名前を入力してください。\n");
    exit(1);
  }
  if((f2=fopen(argv[2], "w+")) == NULL){
    printf("書き込みファイルをオープンできません。\n");
    exit(1);
  }
  printf("コピーする内容/n");
  while((ch=fgetc(f1)) != EOF){
    putchar(ch);
    if(fputc(ch, f2) == EOF){
      printf("書き込みに失敗しました\n");
      exit(1);
    }
  }
  printf("\n\n");
  fclose(f2);
  if((f2=fopen(argv[2],"r")) == NULL){
    printf("書き込みの結果の確認に失敗しました。\n");
    exit(1);
  }
  printf("書き込み結果\n");
  while((ch = fgetc(f2)) != EOF){

    putchar(ch);
  }
  printf("\n");
  fclose(f1);
  fclose(f2);
  return;
}
