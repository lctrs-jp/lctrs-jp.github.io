#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo DAY;

void load(char *filename,DAY list[]);

int main(int argc,char *argv[])
{

  DAY list[10000];

  /*  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
      item.day, item.hour, item.minute, item.content );*/
  int a,b,c,k,year,month,day;
  char buf[300],*filename,content[256];

  filename=argv[2];

  sscanf(argv[1],"%d年%d月%d日",&year,&month,&day);

  load(filename,list);

  for(k=0;k<1000;k++)
	/*	if(item.content!='\0')*/
	printf("%d年%d月%d日　",list[k].year,list[k].month,list[k].day);
  printf("rr");
  return 0;
}
void load(char *filename,DAY list[])
{
  FILE *fp;
  int len,k=0;
  char buf[300];
  if((fp=fopen(filename,"r"))==NULL)
    {
      printf("");
      exit(1);
    }
  while(fgets(buf,256,fp)!=NULL)
    {
      len=strlen(buf);
      if(len>0&&buf[len-1]=='\n')
	{
	  buf[len-1]='\0';
	}
      sscanf(buf,"%d/%d/%d %d:%d %s",&list[k].year,&list[k].month,&list[k].day,&list[k].hour,&list[k].minute,&list[k].content);
      k++;
    } fclose(fp);
}
