#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *txt[])
{
  FILE *fp1,*fp2;
  char a;
  if((fp1=fopen(txt[1],"r"))==NULL){
      printf("ファイルを開く際にエラーが発生しました。\n");
      exit(1);
    }

    if((fp2=fopen(txt[2],"w+"))==NULL){
      printf("ファイルを開くことができません。\n");
      exit(1);
    }
    while(!feof(fp1)){
      a=fgetc(fp1);

      if(!feof(fp1))
      fputc(a,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
    }
