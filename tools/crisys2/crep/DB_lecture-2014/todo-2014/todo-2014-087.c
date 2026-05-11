#include <stdio.h>
#include <stdlib.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content [256];
};

typedef struct todo LIST;

int main(int argc, char *argv[])
{
  LIST to[100];
  FILE *fp;
  char buf[256], *filename;
  int x, y, z, i = 0;

  filename = argv[1];

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("ファイル %s のオープンに失敗しました", filename);
    exit(1);
  }

  while(fgets(buf, 10, fp) != NULL){
    sscanf(buf, "%d/%d/%d", &x, &y, &z );
    if(to[i].year > x)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", to[i].year, to[i].month, to[i].day, to[i].hour, to[i].minute, to[i].content);
    if(to[i].month > y)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", to[i].year, to[i].month, to[i].day, to[i].hour, to[i].minute, to[i].content);
    if(to[i].day > z)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", to[i].year, to[i].month, to[i].day, to[i].hour, to[i].minute, to[i].content);
    i++;
    }

  fclose(fp);

  return 0;
}
