#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  if ((from = fopen(argv[1],"r")) == NULL){
    printf("コピー元のファイルを開くことができませんでした\n");
    exit(1);
  }

  if((to = fopen(argv[2],"r")) != NULL){
    printf("コピー先のファイルが存在しています\n");
    exit(1);
    fclose(to);
  }

  to = fopen(argv[2],"w");

  while(!feof(from)){
    ch = fgetc(from);
    if(ferror(from)){
      printf("コピー元のファイルの読み込みエラー\n");
      exit(1);
    }
    if(!feof(from))
      fputc(ch, to);
    if(ferror(to)){
      printf("コピー先のファイルの書き込みエラー\n");
      exit(1);
    }
  }
  
  fclose(from);
  fclose(to);

  return 0;
}

