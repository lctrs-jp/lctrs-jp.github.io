#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  char ch;
  FILE *fp1, *fp2;
  char *file1, *file2;

  file1 = argv[1];
  file2 = argv[2];

  /* 読み込みのためにコピー元のファイルを開く*/
  /*コピー元のファイルが存在しない場合はメッセージを表示して処理を中止*/
  if((fp1 = fopen(file1, "r"))
     == NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);
  }

  /*コピー先のファイルが存在しない場合はメッセージを表示して処理を中止*/ 
  if((fp2 = fopen(file2, "r"))
     != NULL){
    printf("コピー先のファイルが既に存在します\n");
    exit(1);
  }

  /* 書き込みのためにコピー先のファイルを開く*/
  fp2 = fopen(file2, "w");  

  /* ファイルを読み込み、同時に書き込む*/
  for(;;){
    if((ch = fgetc(fp1)) == EOF)
      break;
    fputc(ch, fp2);
  }

  fclose(fp1);
  fclose(fp2);
  
  return 0;
}
