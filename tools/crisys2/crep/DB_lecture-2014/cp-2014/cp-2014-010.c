#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

 
  if (argc < 3){
    printf ("使用法: <プログラム名> <コピー元> <コピー先>\n");
    exit(1);
  }


  if ((from = fopen(argv[1], "r")) == NULL) {
    printf ("コピー元ファイルを開くことができません\n");
    exit(1);
  }


  if ((to = fopen(argv[2], "r"))!= NULL) {
    printf ("コピー先のファイルが既に存在しています\n");
    exit(1);
  }
  else
    to = fopen(argv[2],"w");


  while ((ch = fgetc(from))!=EOF) {
    fputc (ch, to);
  }
  fclose(from);
  fclose(to);

  return 0;
}
    
   
