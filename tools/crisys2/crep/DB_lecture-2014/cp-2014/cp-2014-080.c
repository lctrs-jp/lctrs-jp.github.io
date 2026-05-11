#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch ;

  /*コマンドラインに指定された因数の数が正しいかどうか調べる*/
  if( argc != 3 )
    exit(1);

  /*コピー元ファイルを開く、コピー元ファイルが存在しない場合はエラーを表示*/
  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("Can't find the source file\n");
    exit(1);
  }

  /*コピー先ファイルが既に存在する場合、エラーを表示*/
  if((fp2 = fopen(argv[2], "r")) != NULL){
    printf("The destination file has already existed\n");
    exit(1); 
  }
    /*コピー先ファイルを開く*/
  if((fp2 = fopen(argv[2], "w")) == NULL){
    printf("Can't open the destination file\n");
    exit(1);
  }

  /*ファイルをコピーする*/
  while( !feof(fp1)){
    ch = fgetc(fp1);
    if(ferror(fp1)){
      printf("Error input\n");
      exit(1);
    }
    if(!feof(fp1))
      fputc(ch, fp2);
    if(ferror(fp2)){
      printf("Error output\n");
      exit(1);
    }
  }

  /*ファイルを閉じる*/
  fclose(fp1);
  
  fclose(fp2);
  
  return 0;
} 
