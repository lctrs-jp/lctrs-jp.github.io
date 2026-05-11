#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *from,*to;
  char ch;

  if(argc!=3){
    printf("使用法：<プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }

  /*コピー元のファイルの有無の判定*/
  if((from=fopen(argv[1],"rb"))==NULL){
    printf("コピー元ファイルが存在しません。\n");
    exit(1);
  }

  /*コピー先のファイルの有無の判定*/
  if((to=fopen(argv[2],"rb"))!=NULL){
    printf("コピー先ファイルと同じ名前のファイルが既に存在しています。\n");
    exit(1);
  }

  /*コピー先のファイルを作成する*/
  if((to=fopen(argv[2],"wb"))==NULL){
    printf("コピー先ファイルの読み込みエラー。\n");
    exit(1);
  }

  /*コピー元のファイルからコピー先のファイルへデータをコピー*/
  while(!feof(from)){
    ch=fgetc(from);

    if(ferror(from)){
      printf("コピー元ファイルの読み込みエラー\n");
      exit(1);
      }

    if(!feof(from)){
      fputc(ch,to);
    }
  }
   
 /*コピー先のファイルの書き込みエラーの有無*/
    if(ferror(to)){
      printf("コピー先ファイルの書き込みエラー\n");
      exit(1);
     }

  /*コピー元のファイルを閉じる*/
  if(fclose(from)==EOF){
    printf("コピー元ファイルを閉じる際のエラー\n");
    exit(1);
  }

  /*コピー先のファイルを閉じる*/
  if(fclose(to)==EOF){
    printf("コピー先ファイルを閉じるときのエラー\n");
      exit(1);  
  }
  return 0;
}
