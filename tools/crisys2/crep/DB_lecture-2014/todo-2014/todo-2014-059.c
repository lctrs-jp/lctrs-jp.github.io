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

int main(int argc, char *argv[])
{
  struct todo list[100];
  int k, n=0, y, m, d, len;
  FILE *fp;
  char buf[256];

  fgets(buf,256,argv[1]);
  sscanf(buf,"%d/%d/%d", y, m, d);

  if((fp=fopen(argv[2],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }

  while (fgets(buf,256,fp)!=NULL){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n') buf[len-1]='\0';
    sscanf(buf,"%d/%d/%d %d:%d %s", &list[n].year, &list[n].month, &list[n].day, &list[n].hour, &list[n].minute, list[n].content);
    n++;
  }

  fclose(fp);

  for(k=0;k<n;k++){
    if(list[k].year<y) continue;
    else if(list[k].year==y&&list[k].month<m) continue;
    else if(list[k].month==m&&list[k].day,d) continue;
    else
  printf("%4d/%2d/%2d %2d:%.2d %s\n", list[k].year, list[k].month,
		list[k].day, list[k].hour, list[k].minute, list[k].content);
  }

  return 0;
}
