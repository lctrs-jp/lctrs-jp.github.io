#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int split(char buf[],char *out[]);

int main(int argc,char *argv[])
{
  struct todo item[100],tmp;
  int i,j,k=0, n,date,time,len;
  FILE *fp;
  char *out[100],buf[256];

  if(argc<2){
    printf("\n",argv[0]);
    exit(1);
  }

  for(i=1;i<argc;i++){
    if((fp=fopen(argv[i],"r"))==NULL){
      exit(1);
    }

    while(fgets(buf,256,fp)!=NULL){
      len=strlen(buf);
      if(len>0 && buf[len-1]=='\n')
	buf[len-1]='\0';
      n=split(buf,out);
      if(n==0)
	continue;
      else if(n<3)
	printf("適切なファイルを指定してください");
      else{
	date=atoi(out[0]);
	item[k].year=date/10000;
	item[k].month=(date%10000)/100;
	item[k].day=(date%100);
	time=atoi(out[1]);
	item[k].hour=time/100;
	item[k].minute=time%100;
	strncpy(item[k].content,out[2],256);
	k++;
      }
    }
    fclose(fp);
  }



  int a;

  printf("指定日を入力してください（例2014年9月30日→20140930）");
  scanf("%d",&a);
  for(i=0;i<k;i++){
    if(a < (item[i].year)*10000 + (item[i].month)*100 + (item[i].day))
      printf("%4d/%2d/%2d %2d:%.2d %s\n",item[i].year,item[i].month,item[i].day,item[i].hour,item[i].minute,item[i].content);}

  return 0;

}

int split(char buf[], char *out[])
{ int count=0,f=0;
  while (*buf)
    { if (*buf != ' ' && f==0)
	{ *out = buf;
	  count++; out++;
	  f = 1;
	}
      else if (*buf ==' ')
	{ *buf='\0';
	  f = 0;
	}
      buf++;
    }
  return count;
}
