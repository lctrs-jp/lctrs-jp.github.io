#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp1, *fp2;
  char ch;

  if((fp2 = fopen("dest.txt", "r")) != NULL){
    printf("コピー先のファイルが存在します\n");
    fclose(fp2);
    exit(1);
  }

  if((fp2 = fopen("dest.txt", "w")) == NULL){
    printf("コピー先ファイルが開きません\n");
    exit(1);
  }

  if((fp1 = fopen("source.txt", "r")) == NULL){
    printf("コピー元ファイルが開きません\n");
    exit(1);
  }

  /* コピーする */
  while((ch = fgetc(fp1)) != EOF)
    fputc(ch, fp2);

  fclose(fp1);
  fclose(fp2);

  return 0;
}
