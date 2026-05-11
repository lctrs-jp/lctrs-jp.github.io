#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100;

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content [256];
};

typedef struct todo DATA;

int lord(char *memo2,DATA item2[]);

int main(int argc,char *argv[])
{
  DATA item[MAX+1];
  argv[1]=date;
  argv[2]=memo;
  int i,num;
  char str[300];

  if(argc != 3)
    {
      printf("ファイル名と日時の両方を入力してください。\n");
      exit(1);
    }

  sscanf(date,"%d/%d/%d", &item[MAX].year, &item[MAX].month, &item[MAX].day);

  num=lord(memo,item);

  for(i=0,i<num;i++)
    {
      sprintf(str,"%d/%d/%d %d:%d %s",item[i].year,item[i].month,item[i].day,item[i].hour,item[i].minute,item[i].content);
      printf("%s\n",str);
    }

  return 0;
}

int lord(char *memo2,DATA item2[])
{
  FILE *fp;
  int i;
  int j=0;
  int y,mo,d,h,mi;
  int len;
  char s[256];
  char ch[300];

  fp=fopen(memo2);
  if(fp==NULL)
    {
      printf("データがありません");
      exit(1);
    }

  for(i=0;fgets(ch,300,fp);i++)
    {
      len=strlen(ch);
      if(len>0 && ch[len-1]=='\n')
	buf[len-1]='\0';

      sscanf(ch,"%d/%d/%d %d:%d %s",y,mo,d,h,mi,s);
      if(y<item2[MAX].year)
	y=0;
      else if(mo<item2[MAX].month)
	mo=0;
      else if(d<item2[MAX].month)
	d=0;
      else
	{
	  item2[j].year=y;
	  item2[j].month=mo;
	  item2[j].day=d;
	  item2[j].hour=h;
	  item2[j].minute=mi;
	  j++;
	}
    }
  fclose(fp);
  return j;
}
