#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/*
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
  };*/

int main(int argc, char *argv[])
{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
  char buf[MAX];
  FILE *fp;
  if((fp = fopen("mytodo.txt", "r")) == NULL){
    printf("ファイルを開けませんでした\n");
    exit(1);
  }
  while(fgets(buf,MAX,fp) != NULL){
    sscanf(buf, "%4d/%2d/%2d %2d:%2d %s\n", &year, &month, &day, &hour, &minute, &content);

    printf("%4d/%2d/%2d %2d:%2d %s\n", year, month, day, hour,  minute,  content );
  }
  return 0;
}
