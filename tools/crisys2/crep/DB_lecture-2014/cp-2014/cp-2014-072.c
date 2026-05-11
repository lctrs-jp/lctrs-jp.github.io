#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  FILE *fp1,*fp2;
  char ch, *p;
  //コピー元のファイルを開く
  if((fp1 = fopen(argv[1], "r")) == NULL){

    printf("読み込みファイルのオープンに失敗しました。\n");
    exit(1);

  }
  //コピー先に指定したのと同じ名前のファイルが存在したら終了する
  if((fp2 = fopen(argv[2], "r")) != NULL){

    printf("書き込みファイルと同じ名前のファイルがすでに存在しています。別のファイル名を入力してください。\n");
    exit(1);

  }
  //コピー先のファイルを作成する
  if((fp2 = fopen(argv[2], "w+")) == NULL){
    
    printf("書き込みファイルのオープンに失敗しました。\n");
    exit(1);
    
  } 
  //コピー元からコピー先に一文字ずつ文字をコピーしていく
  printf("コピーする内容\n");
  while((ch = fgetc(fp1)) != EOF){
    
    putchar(ch);
    
    if(fputc(ch, fp2) == EOF){
      
      printf("書き込みに失敗しました。\n");
      exit(1);

    }

  }

  printf("\n\n");
 
  fclose(fp2);
  //ちゃんとコピーされているか確認するために読み込みモードで開きなおしてコピー先の文字を読みとって表示する
  if((fp2 = fopen(argv[2], "r")) == NULL){

    printf("書き込み結果の確認に失敗しました。\n");
    exit(1);

  }
  printf("書き込み結果\n");
  while((ch = fgetc(fp2)) != EOF){
 
    putchar(ch);

  }

  printf("\n");

  fclose(fp1);
  fclose(fp2);

  return;
}
