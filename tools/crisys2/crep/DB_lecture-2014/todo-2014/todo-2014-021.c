#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define LEN 256
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[])
{
  FILE *fp;
  struct todo item[MAX];
  char buf[LEN];
  int i,x;
  int l,j,k;
  if(argc != 3){
    printf("ex2-xxxxxxx 日にち　ファイル名");
    exit(1);
  }

  if((fp = fopen(argv[2],"r"))==NULL){
    printf("ファイルがありません");
    exit(1);
 }

  for(i=0;;i++){
    if(fgets(buf,sizeof(buf),fp)==NULL)
      break;
    x = strlen(buf);
    sscanf(buf,"%4d/%2d/%2d %2d:%2d %s\n",&item[i].year, &item[i].month, &item[i].day, &item[i].hour, &item[i].minute, item[i].content);
  }

  fclose(fp);
  x = i;
  sscanf(argv[1],"%4d/%2d/%2d",&l,&j,&k);

  for(i=0;i<x;i++){
    if(l<=item[i].year)
      if(j<=item[i].month)
	if(k<=item[i].day)
	  printf("%4d/%2d/%2d %2d:%2d %s\n",item[i].year, item[i].month, item[i].day, item[i].hour, item[i].minute, item[i].content);
  }
  return 0;
}
