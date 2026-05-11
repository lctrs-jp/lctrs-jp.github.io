#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp,*fq ;
  if((fp=fopen("argv[1]","r"))==NULL){
    printf("can't open file\n");
    exit(1);
  }
  if((fq=fopen("argv[2]","w"))==NULL){
    printf("can't open file\n");
    exit(1);
  }
  int fputc(int c,FILE *fp);
  int fgetc(FILE *fq);
  fclose(fp);
  fclose(fq);

  return 0;
}
