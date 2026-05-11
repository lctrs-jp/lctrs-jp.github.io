#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  FILE *s1,*s2;
  char ch;

  if((s2=fopen("dest.txt","r") )!=NULL){
  printf("コピー先のファイルが存在\n");
  fclose(s2);
  exit(1);
  }

  if((s2=fopen("dest.txt","w") )==NULL){
    printf("コピー先のファイルが存在しない\n");
    exit(1);
  }

  if((s1=fopen("source.txt","r") )==NULL){
    printf("コピー先のファイルが存在しない\n");
    exit(1);
  }

  while((ch=fgetc(s1))!=EOF)
    fputc(ch,s2);

  fclose(s1);
  fclose(s2);

  return 0;
}
