#include <stdio.h>
#include <stdlib.h>

int main(char argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch, *p;
 
  //読み込みのために指定されたファイルを開く
  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("ファイルをオープンできませんでした。\n");
    exit(1);
  }
  
  //書き込み用ファイルがある場合終了する
  if((fp2 = fopen(argv[2], "r")) != NULL){
    printf("ファイルが既に存在します。違うファイル名を入力してください。\n");
    exit(1);
  }
  //書き込み用のファイルを作る
  if((fp2 = fopen(argv[2], "w")) == NULL){
    printf("ファイルを作成できませんでした。\n");
    exit(1);
  }

  //argv[1]の内容を読み込む・書き込む
  while (!feof(fp1)){
    ch = fgetc(fp1);   
    fputc(ch,fp2);
  }
  fclose(fp1);
  fclose(fp2);

  return 0;
}
