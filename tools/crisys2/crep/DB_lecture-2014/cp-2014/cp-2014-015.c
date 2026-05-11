
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *from, *to, *fp;
  char ch, *p;


  
  if(argc < 3){
    printf("使用法：＜プログラム名＞＜コピー元＞＜コピー先＞\n");
    exit(1);
  }
  
  /* 読み込みのために開く*/
  if((fp = fopen(argv[1], "r"))
     == NULL){
    printf("Can't open file\n");
    exit(1);
  }
  /* ファイルを読み込み直す*/
  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
    putchar(ch);
  }
  fclose(fp);


  /* 読み込みのために開く*/
  if((fp = fopen(argv[2], "r"))
     == NULL){
    printf("Can't open file\n");
    exit(1);
  }
  /* ファイルを読み込み直す*/
  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
    putchar(ch);
  }
  fclose(fp);




  if((from = fopen(argv[1],"r"))==NULL){
    printf("コピー元ファイルを開くことができません。\n");
    exit(1);
  }
  
  if((to = fopen(argv[2],"w"))==NULL){
    printf("コピー先ファイルを開くことができません。\n");
    exit(1);
  }
  




  while((ch = fgetc(from)) != EOF){
    fputc(ch,to);
  }
  fclose(from);
  fclose(to);

  /* 読み込みのために開く*/
  if((fp = fopen(argv[1], "r"))
     == NULL){
    printf("Can't open file\n");
    exit(1);
  }
  /* ファイルを読み込み直す*/
  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
    putchar(ch);
  }
  fclose(fp);


  /* 読み込みのために開く*/
  if((fp = fopen(argv[2], "r"))
     == NULL){
    printf("Can't open file\n");
    exit(1);
  }
  /* ファイルを読み込み直す*/
  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
    putchar(ch);
  }
  fclose(fp);



  return 0;
}
