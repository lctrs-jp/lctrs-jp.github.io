#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main (int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  if( argc != 3 ){
    printf("使用法:<プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }

  if((from = fopen(argv[1], "r" )) == NULL){
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  if((to = fopen(argv[2], "w")) == NULL){
    printf("コピー先ファイルを開くことができません\n");
    exit(1);
  }
  while(!feof(from)){
    ch = fgetc(from);
    if(!feof(from))
      fputc(ch, to);
  }

  fclose(from);
  fclose(to);

  return 0;
}
