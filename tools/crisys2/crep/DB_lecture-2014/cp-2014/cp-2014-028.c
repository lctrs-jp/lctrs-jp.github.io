#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
  FILE *fp1,*fp2;
  char a;
  argc=3;

  if((fp1=fopen(argv[1],"r"))==NULL){
    printf("コピー元ファイルを開くことができません\n");
    exit(1);
  }

  if((fp2=fopen(argv[2],"w"))==NULL){
    printf("コピー先ファイルファイルを開くことができません\n");
    exit(1);
  }
  

  while((a=fgetc(fp1))!=EOF){
    fputc(a,fp2);
    putchar(a);
  }
  fclose(fp1);
  fclose(fp2);

  return 0;
}
