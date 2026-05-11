#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
} TODO;

void removeenter(char *buf)
{
  int i=0;

  for(;*(buf+i)!='\0';i++);
  if(*(buf+i-1)=='\n')
    *(buf+i-1)='\0';
  return;
}

int loadfile(char *fname,TODO *list)
{
  FILE *fp;
  int size=0,i=0,flag=0;
  char tmp[512];

  if((fp=fopen(fname,"r"))==NULL)
    {
      printf("Can't load file");
      exit(1);
    }
  while(1)
    {
      if(fgets(tmp,512,fp)==NULL)
	break;
      removeenter(tmp);
      flag=0;
      while(tmp[i])
	{
	if(tmp[i]!=' ')
	  {
	    flag=1;
	    break;
	  }
	}
      if(flag==0)
	continue;
      sscanf(tmp,"%d/%d/%d%d:%d %s",&list[size].year,&list[size].month,
	     &list[size].day,&list[size].hour,&list[size].minute,
	     list[size].content);
      size++;
    }
  return size;
}

void seek(int size,char *chdate,TODO *list)
{
  char tmp[11];
  int i=0;

  while(i<size)
    {
      sprintf(tmp,"%4d/%2d/%2d",list[i].year,list[i].month,list[i].day);
      if(strcmp(tmp,chdate)>=0)
	{
	  printf("%4d/%2d/%2d %2d:%.2d %s\n",list[i].year,list[i].month,
		 list[i].day,list[i].hour,list[i].minute,
		 list[i].content);
	}
      i++;
    }
  return;
}



int main(int argc,char *argv[])
{
  int size;
  TODO item[100];
  
  if(argc<=2)
    {
      printf("Input date and file name");
      exit(1);
    }

  size=loadfile(argv[2],item);
  seek(size,argv[1],item);


  return 0;
}
