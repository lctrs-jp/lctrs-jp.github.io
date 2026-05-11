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
} item[100];

int main(int argc, char *argv[])
{
  FILE *fp;
  int i,  num = 0;
  char buf[100], time[100],now[100];
  int nowy,nowm,nowd;
  if((fp = fopen(argv[2], "r")) == NULL){
    printf("ファイルを開けませんでした\n");
    exit(1);
  }
  for(i = 0; fgets(buf,1000, fp) != NULL; i++){
    sscanf(buf,"%4d/%2d/%2d %2d:%2d %s\n",&item[i].year, &item[i].month, &item[i].day, &item[i].hour, &item[i].minute, item[i].content);
    num++;
  }
  sscanf(argv[1], "%4d/%2d/%2d", &nowy,&nowm,&nowd);
  sprintf(now, "%.4d%.2d%.2d",nowy, nowm, nowd);
  for(i = 0; i < num; i++){
    sprintf(time, "%.4d%.2d%.2d",item[i].year, item[i].month, item[i].day);
    if(strcmp(time, now)> 0) 
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n", item[i].year, item[i].month,
	     item[i].day, item[i].hour, item[i].minute, item[i].content );}
  return 0;
}
