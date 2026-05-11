#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp1,*fp2;
  char ch;

  if(argc!=3){
    printf("ファイル名を２つ入力してください\n");
    exit(1);
  }
  if((fp1=fopen(argv[1],"r"))==NULL){
    printf("コピー元ファイルを開けませんでした\n");
    exit(1);
  }
  if((fp2=fopen(argv[2],"r"))!=NULL){
    fclose(fp1);
    fclose(fp2);
    printf("その名前のファイルが既に存在しています\n");
    exit(1);
  }
  fp2=fopen(argv[2],"w");

  while(1){
    if((ch=fgetc(fp1))==EOF)
      break;
    if(fputc(ch,fp2)==EOF){
      printf("書きこみエラーが発生しました\n");
      exit(1);
    }
  }
  fclose(fp1);
  fclose(fp2);

  printf("コピーに成功しました\n");

  return 0;
}
