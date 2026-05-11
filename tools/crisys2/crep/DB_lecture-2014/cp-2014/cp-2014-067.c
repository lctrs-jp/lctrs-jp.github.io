#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  //コピー元ファイルを開く
  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("Can't open file of source\n");
    exit(1);
  }

 //コピー先ファイルが存在しないか確認する
  if((fp2 = fopen(argv[2], "r")) == NULL) {

    if((fp2 = fopen(argv[2], "w")) == NULL){
       printf("Can't open file of dest\n");
       exit(1);
      }
    }

  //もしコピー先ファイルがあったら強制終了
   else {
     printf("コピー先ファイルはすでに存在しています\n");
     exit(1);
   }

  //ファイルをコピーする
  while(!feof(fp1)){
    ch = fgetc(fp1);
    if(ferror(fp1)){
      printf("コピー元ファイルの読み込みエラー\n");
      exit(1);
    }
    if(!feof(fp1)) 
      fputc(ch, fp2);
    if(ferror(fp2)){
      printf("コピー先ファイルの書き込みエラー\n");
      exit(1);
    }
  }

  if(fclose(fp2) == EOF) {
    printf("Can't close file of dest\n");
    exit(1);
  }

  if(fclose(fp1) == EOF) {
    printf("Can't close file of dest\n");
    exit(1);
  }


  return 0;
}
