#include <stdio.h>
#include <stdlib.h>

/*ファイルをコピーするプログラム*/
int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  if(argc != 3){
    puts("引数の数が違います");
    exit(1);
  }

  /*コピー元のファイルを開く*/
  if((fp1 = fopen(argv[1],"rb")) == NULL){
    puts("コピー元のファイルが開けません");
    exit(1);
    }

  /* コピー先のファイルを調べる*/
 if((fp2 = fopen(argv[2],"rb")) != NULL){
    puts("コピー先のファイルが存在します");
    exit(1);
    } 
 if((fp2 = fopen(argv[2],"wb")) == NULL){
    puts("コピー先のファイルの作成出来ません");
    exit(1);
    } 

 /*ファイルの内容をコピーする*/
 while((ch = fgetc(fp1)) != EOF){
     fputc(ch, fp2);
 } 

 fclose(fp1);
 fclose(fp2);

 return 0;
}
