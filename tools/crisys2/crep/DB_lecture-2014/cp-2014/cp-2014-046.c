#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  /* 書き込みのためにargv[2]を作成*/
  if((fp2 = fopen(argv[2],"wb")) == NULL){
    printf("コピー先のファイルが開けません!\n");
    exit(1);
  }

  /*argv[1]を読み込むために開く */
  if((fp1 = fopen(argv[1],"rb")) == NULL){
    printf("コピー元のファイルが開けません!\n");
    exit(1);
  }

  /* argv[2]にargv[1]を書き込む*/
  while (!feof(fp1)){
    ch = fgetc(fp1);
    if(ferror(fp1)){
      printf("コピー元のファイルが読み込めません!\n");
      exit(1);
    }
    if(!feof(fp1))
      fputc(ch, fp2);
    if(ferror(fp2)){
      printf("コピー先のファイルに書き込めませんでした!\n");
      exit(1);
    }
  }

  if(fclose(fp1) == EOF){
    printf("コピー元のファイルを閉じれませんでした!\n");
    exit(1);
  }

  if(fclose(fp2) == EOF){
    printf("コピー先のファイルを閉じることができませんでした!\n");
    exit(1);
  }

  return 0;
}
