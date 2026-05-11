#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 256

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char  content[MAX];
};

int main(int argc, char *argv[])
{
  struct todo yotei[100];
  int i, j, k = 0, n, date, time, len;
  FILE *fp;
  char  buf[MAX];

  if(argc != 3){
    printf("年月日とファイルを指定してください\n");
    exit(1);
  }

    if((fp = fopen(argv[2],"r"))== NULL){
      fprintf(stderr,"Error\n");
      exit(1);
    }
    while(fgets(buf, MAX, fp) != NULL){
      sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s\n", &yotei[i].year, &yotei[i].month, &yotei[i].day, &yotei[i].hour, &yotei[i].minute, &yotei[i].content);
  printf("%4d/%2d/%2d %2d:%.2d %s\n", yotei[i].year, yotei[i].month, yotei[i].day, yotei[i].hour, yotei[i].minute, yotei[i].content);
    }

  return 0;
}

