#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  if((fp1 = fopen(argv[1], "r+")) == NULL){
    printf("コピー元のファイルが開けません。\n");
    exit(1);
  }

  if((fp2 = fopen(argv[2], "r+")) != NULL){
    printf("コピー先のファイルが既に存在しています。\n");
    exit(1);
  }
 
  fp2 = fopen(argv[2], "w+"); 

  while(!feof(fp1)){
    ch = fgetc(fp1);
    if(!feof(fp1))
      fputc(ch, fp2);
  }
  fclose(fp1);
  fclose(fp2);

  printf("コピーが完了しました。\n");

  return 0;
}
