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

int main(int argc,char *argv[])
{
  FILE *fp;
  char *filename,cont;
  char buf=*argv[1];
  int x,y,z,yr,m,d,h,min;

  
  filename=argv[1];
  if((fp=fopen(filename,"r"))==NULL){
    printf("ファイルのオープンに失敗しました");
    exit(1);
  }
  fscanf(fp,"%4d/%3d/%3d %3d:%3d %s", &yr,&m,&d,&h,&min,&cont);
  struct todo item = { yr, m, d, h, min, cont};
  printf("%4d/%2d/%2d %2d:%.2d %s \n ", item.year, item.month,item.day, item.hour, item.minute,item.content);
  
  

  return 0;
}
