#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char ch;
  FILE *src, *trg;

  if((src=fopen(argv[1],"r"))==NULL) {
    printf("Can't open sorcefile\n");
    exit(1);
  }

  if((trg=fopen(argv[2],"w"))==NULL) {
    printf("Can't open targetfile\n");
    exit(1);
  }

  while ((ch=fgetc(src))!=EOF) {
    fputc(ch, trg);
  }

  fclose(src);
  fclose(trg);

  return 0;
}
