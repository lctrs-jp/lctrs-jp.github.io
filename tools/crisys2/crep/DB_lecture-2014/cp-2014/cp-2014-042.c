#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *file1, *file2;
  char aa;
   
  /* コピー元ファイルを開く */
  if ((file1 = fopen(argv[1], "r")) == NULL) {
    printf("コピー元ファイルを開けません\n");
    exit(1);
  }

  /* コピー先ファイルを開く */
  if ((file2 = fopen(argv[2], "w")) == NULL) {
    printf("コピー先ファイル開けません\n");
    exit(1);
  }

  /* ファイルをコピーする */
 
  while (!feof(file1)) {
    aa = fgetc(file1);
    if (!feof(file1)) 
      fputc(aa, file2);
  }


  /* ファイルを閉じる */
  fclose(file1);
  fclose(file2);
  return 0;
}
