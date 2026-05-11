#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void loadfile(char *fname);

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item[MAX];
int n = 0;

int main(int argc, char *argv[])
{
  int x, y, z;
  int i;
  if (argc != 3){
    printf("Usage: ./ex2 2014/12/11 mytodo.txt");
  return 0;
  }
  sscanf(argv[1], "%d/%d/%d", &x, &y, &z);
  loadfile(argv[2]);

  for (i = 0; i < n; i++) {
  if (x <= item[i].year && y <= item[i].month, z<= item[i].day)
    printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n", item[i].year, item[i].month, item[i].day ,item[i].hour, item[i].minute, item[i].content);
  }
  return 0;
}

void loadfile(char *fname) { /* ファイルの読み込み */
  FILE *fp;
  char buf[1000];
  if((fp = fopen(fname, "r")) == NULL ){
    printf("ファイルのオープンに失敗しました");
    exit(1);
  }
  while(fgets(buf,1000,fp) != NULL ){
    sscanf(buf,"%4d/%2d/%2d %2d:%2d %s", &item[n].year, &item[n].month, &item[n].day ,&item[n].hour, &item[n].minute, &item[n].content);
    n++;
  }
  fclose(fp);
  return;
}
