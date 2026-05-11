#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
  FILE *text, *copy;
  char ch; 

  if((text = fopen(argv[1], "r")) == NULL) {
    printf("コピー元ファイルを開くことはできません\n");
    exit(1);
  }

  if(copy = fopen(argv[2], "r"))  {
    printf("コピー先ファイルは既に存在します\n");
    exit(1);
  }

  if((copy = fopen(argv[2], "w")) == NULL) {
    printf("コピー先ファイルを開くことはできません\n");
    exit(1);
  }

  while(1) {
     if((ch = fgetc(text)) == EOF)
      break;
   else{
    fputc(ch, copy);
   }
  }
  fclose(text);
  fclose(copy);

  return 0;
}
