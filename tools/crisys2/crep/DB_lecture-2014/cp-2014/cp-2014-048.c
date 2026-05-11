#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){ 
  FILE *fp1;
  FILE *fp2;
  char t[100];
  int c,m;
  if((fp1=fopen(argv[1],"r"))==NULL){
    printf("%sよ、貴様など知らぬ　帰れ",argv[1]);
    exit(1);}
  if((fp2=fopen(argv[2],"r"))!=NULL){
    printf("%sはすでに存在している　下衆め　帰れ",argv[2]);
    exit(1);}
  fp2=fopen(argv[2],"w+");
  while((c=fgetc(fp1))!=EOF)
    fputc(c,fp2);
  fclose(fp1);
  fclose(fp2);
 return 0;
}
