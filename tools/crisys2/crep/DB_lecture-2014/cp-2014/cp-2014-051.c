#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  //引数の確認
  if(argc != 3){
    printf("プログラム名、コピー元、コピー先の3つを入力\n");
    exit(1);
  }

  // コピー元ファイルを開く
  if((fp1=fopen(argv[1],"r")) == NULL){
    printf("コピー元ファイルを開けませんでした\n");
    exit(1);
  }

  // コピー先ファイルを開く
  if((fp2=fopen(argv[2],"r")) != NULL){
    printf("コピー先ファイルが既に存在します\n");
    exit(1);
  }
  if((fp2=fopen(argv[2],"w+")) == NULL){
    printf("コピー先ファイルを開けませんでした\n");
    exit(1);
  }

  // コピー元を読み込む
  while(!feof(fp1)){
    ch = fgetc(fp1);
    if(ferror(fp1)){
      printf("コピー元ファイルの読み込みエラー\n");
      exit(1);
    }

  // コピー先に書き込む
    if(!feof(fp1))
      fputc(ch,fp2);
    if(ferror(fp2)){
      printf("コピー先ファイルへの書き込みエラー\n");
      exit(1);
    }
  }

  // ファイルを閉じる
  fclose(fp1);
  fclose(fp2);

  return 0;
}
