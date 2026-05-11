#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  if(argc !=3){
    printf("使用法:<コピー元><コピー先>\n");
    exit(1);
  }

  if((from = fopen(argv[1], "rb")) == NULL){
    printf("コピー元ファイルが開けません\n");
    exit(1);
  }

  if((to = fopen(argv[2], "wb")) == NULL){
    printf("コピー先ファイルが開けません\n");
    exit(1);
  }

  while (!feof(from)){
    ch = fgetc(from);
    if(ferror(from)){
      printf("コピー元の書き込みエラー\n");
      exit(1);
    }
    if(!feof(from))
      fputc(ch, to);
    if(ferror(to)){
      printf("コピー先の書き込みエラー\n");
      exit(1);
    }
  }
  
  if(fclose(from) == EOF){
    printf("コピー元ファイルを閉じれません\n");
    exit(1);
  }
  
  if(fclose(to) ==EOF){
    printf("コピー先ファイルを閉じる際のエラー\n");
    exit(1);
  }
  
  return  0;
}
