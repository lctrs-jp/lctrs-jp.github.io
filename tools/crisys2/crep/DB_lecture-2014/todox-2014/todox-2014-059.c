#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

typedef struct todo TODO;

int main(int argc, char *argv[])
{
  TODO list[MAX];

  if(argc != 3) {
    printf("使用法: <プログラム名> <ファイル名>\n");
    exit(1);
  }

  FILE *fp;
  char buf[MAX];
  int time[MAX];
  int i, j, num;

  //ファイルのオープン
  if((fp = fopen(argv[2], "r")) == NULL) {
    printf("ファイルのオープンエラー\n");
    exit(1);
  }

  while(!feof(fp)) {
    for(i = 0; i < MAX; i++) {
      sscanf(buf, "%d/%d/%d %d:%d %s", list[i].year, list[i].month, list[i].day, list[i].hour, list[i].minute, list[i].content);
      sprintf(time[i], "%d%d%d", list[i].year, list[i].month, list[i].day);
    }
  }

  for(j = 0; j < MAX; j++)
    if(strcmp(time[j], argv[1]))
      j = num;

  for(j = num; j < MAX; j++)
    printf("%s", list[j]);

  fclose(fp);

  return 0;
}

