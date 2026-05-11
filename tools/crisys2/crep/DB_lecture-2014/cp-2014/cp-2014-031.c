#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char str;

  /*ファイル指定方法が正しくない場合*/
  if(argc != 3){
    printf("入力が正しくありません\n");
    exit(1);
  }
    
  /*コピー先のファイルが既に存在する場合はプログラム終了*/
  if((to = fopen(argv[2], "r")) != NULL){
    printf("コピー先ファイルが既に存在しています\n");
    exit(1);
  }

  /*コピー元ファイルを開き、存在しない場合はプログラム終了*/
  if((from = fopen(argv[1], "r")) == NULL){
      printf("コピー元ファイルが存在しません\n");
      exit(1);
    }

    /*コピー先ファイルを作成して開く*/
  if((to = fopen(argv[2], "w+")) == NULL){
	printf("コピー先ファイルを開けません\n");
	exit(1);
      }

      while(!feof(from)){
	str = fgetc(from);
	if(ferror(from)){
	  printf("コピー元ファイルの読み込みエラー\n");
	  exit(1);
	}
	if(!feof(from))
	  fputc(str, to);
	if(ferror(to)){
	  printf("コピー先ファイルの書き込みエラー\n");
	  exit(1);
	}
      }
  
      /*ファイルを閉じる*/
      if(fclose(from) == EOF){
	printf("コピー元ファイルを閉じる際のエラー\n");
	exit(1);
      }

      if(fclose(to) == EOF){
	printf("コピー先ファイルを閉じる際のエラー\n");
	exit(1);
      }
      
      return 0;
}
