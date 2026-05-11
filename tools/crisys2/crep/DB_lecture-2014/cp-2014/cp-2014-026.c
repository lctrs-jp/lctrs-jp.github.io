#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  if (argc != 3) {
    printf("使用法: <プログラム名> <ファイル名>\n");
    exit(1);
  }

  if ((from = fopen(argv[1], "r")) != NULL) {
    printf("上書きです\n");
    exit(1);
  }

  if ((to = fopen(argv[2], "w")) == NULL) {
    printf("コピー先のファイルを開けません\n");
    exit(1);
  }

  while ((ch = fgetc(from)) != EOF)
    fputc(ch, to);

  fclose(from);
  fclose(to);

  return 0;
}
