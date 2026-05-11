#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int aa, bb, cc, dd, ee;

int main(int argc, char *argv[])
{
  FILE *fp;
  int c, x;
  x = 0;

  /* ファイルを開くのに失敗したら */
  /* プログラムを終了して、シェルに戻る */
  if ((fp = fopen( "mytodo.txt", "r")) == NULL) {
    fprintf(stderr, "Can't Open File\n");
    exit(2);
  }

  /* ファイルの終わりに達するまで */
  while ((c = fgetc(fp)) != EOF) {    /* 一文字読み込み */
    char yo[x] = c;
    x++;
  }
  fclose(fp);

  x = 0;
  for (;;x++)
yo[x] =

  struct todo item = { aa, bb, cc, dd, ee, "プログラミング課題提出" };
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
	 item.day, item.hour, item.minute, item.content );
  return 0;
}
