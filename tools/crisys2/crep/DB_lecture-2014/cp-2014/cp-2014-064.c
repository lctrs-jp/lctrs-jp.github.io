#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char c, w;

  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);
  }

  if((fp2 = fopen(argv[2], "r")) != NULL){
    printf("コピー先のファイルが既に存在しています\n");
    exit(1);
  }

  fp2 = fopen(argv[2], "w");

  while ((c = fgetc(fp1)) != EOF){
    fputc(c, fp2);
    if (w)
      putchar(c);
  }
  fclose(fp1);
  fclose(fp2);

  return 0;
}
