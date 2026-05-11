#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[])
{

  argv[2] = "mycopy_source.txt", "dest.txt";

  int a;
  FILE *fp1,*fp2;

  if((fp2 = fopen(argv[0], "r")) == NULL) {
    printf("読み込み先エラー\n");
    exit(1);
  }
  if((fp1 = fopen(argv[1], "w")) == NULL) {
    printf("書き込み先エラー\n");
    exit(1);
  }

  while((a = fgetc(fp1)) != EOF) {
   fputc(a, fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}
