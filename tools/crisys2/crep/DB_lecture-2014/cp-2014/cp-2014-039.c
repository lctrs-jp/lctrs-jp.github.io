#include<stdio.h>

int main(int argc, char *argv[])
{
  if(argc != 3){
    printf("ERROR\n使用法:<プログラム名> <コピー元ファイル> <コピー先ファイル>\n");
    exit(1);
  }

  FILE *fpr, *fpw;
  char str;

  //読み込み用にファイルを開く
  if((fpr = fopen(argv[1], "r")) == NULL){
    printf("コピー元ファイルが開けませんでした\n");
    exit(1);
  }

  if((fpw = fopen(argv[2],"r")) != NULL){
      printf("警告:コピー先にファイルが存在します\n");
      fclose(fpw);
      exit(1);
    }

  //書き込み用にファイルを開く
  if((fpw = fopen(argv[2], "w")) == NULL){
    printf("警告:ファイルが開けませんでした\n");
    exit(1);
  }
  
  for(;;){
    str = fgetc(fpr);
    if(str == EOF)
      break;
    if(fputc(str, fpw) == EOF){
      printf("書き込み失敗\n");
      exit(1);
    }
  }

  fclose(fpr);
  fclose(fpw);

  //読み込みのためにfpwファイルを開く
  if((fpw = fopen(argv[2], "r")) == NULL){
    printf("ファイルが開けませんでした\n");
    exit(1);
  }

  //ファイルを読み込み直す
  for(;;){
    if((str = fgetc(fpw)) == EOF)
      break;
    putchar(str);
  }
  fclose(fpw);

  return 0;
}

