#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 256

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[LEN];
};

typedef struct todo stodo;
stodo schedule[MAX];

int main(int argc, char *argv[])
{
  FILE *fp;
  int ye, mo, da, ho, mi, i, j=0, k;
  char buf[300], co[LEN], time[10];

  if((fp = fopen(argv[2], "r")) == NULL){
    printf("ファイルを開けませんでした\n");
    exit(1);
  }

  while(fgets(buf, 300, fp) != NULL){
    for(i = 0; buf[i] != '\0'; i++)
      if(buf[i] == '\n')
	buf[i] = '\0';
    sscanf(buf, "%d/%d/%d %d:%d %s", &ye, &mo, &da, &ho, &mi, co);
    schedule[j].year = ye;
    schedule[j].month = mo;
    schedule[j].day = da;
    schedule[j].hour = ho;
    schedule[j].minute = mi;
    for(k = 0; co[k] != '\0'; k++)
      schedule[j].content[k] = co[k];
    j++;
  }

  sscanf(argv[1], "%d/%d/%d", &ye, &mo, &da);
  sprintf(time, "%d%d%d", ye, mo, da);

  for(i = 0; i < j; i++){
    sprintf(buf, "%d%.2d%.2d", schedule[i].year, schedule[i].month, schedule[i].day);
    if(strcmp(buf, time) >= 0)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", schedule[i].year, schedule[i].month, schedule[i].day, schedule[i].hour, schedule[i].minute, schedule[i].content);
  }

  return 0;
}
