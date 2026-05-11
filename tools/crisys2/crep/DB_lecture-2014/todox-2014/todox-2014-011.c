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
int ord(struct todo item1, struct todo item2);

int main(int argc,char *argv[])
{
  struct todo item[100],tmp;
  int i,j,k=0, n,date,time,len;
  FILE *fp;
  char *out[100],buf[256];

  if(argc<2){
    printf("使用法:<プログラム名> <ファイル名>\n");
    exit(1);
  }

  for(i=1;i<argc;i++){
    if((fp=fopen(argv[i],"r"))==NULL){
      printf("ファイルを開くことができません\n");
      exit(1);
    }

    while(fgets(buf,256,fp)!=NULL){
      len=strlen(buf);
      if(len>0 && buf[len-1]=='\n')
	buf[len-1]='\0';
      n = split(buf,out);
      if(n==0)
	continue;
      else if(n<3)
	printf("format error");
      else{
        for(i = 0; i < n; i++){
          sscanf(buf[i],"%4d/%2d/%2d %2d:%2d",&item[i].year,&item[i].month,&item[i].day,&item[i].hour,&item[i].minute);
    }
    fclose(fp);
  }

  for(i=1;i<k;i++){
    for(j=k-1;j>i;j--){
      if(ord(item[j-1],item[j])){
	tmp=item[j-1];
	item[j-1]=item[j];
	item[j]=tmp;
      }
    }
  }
  
  for(i=0;i<k;i++){
    printf("%4d/%2d/%2d %2d:%2d %s\n",item[i].year,item[i].month,item[i].day,item[i].hour,item[i].minute,item[].content);
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


int ord(struct todo item1, struct todo item2)
{
  int date1,date2,time1,time2;

  date1=item1.year*10000+item1.month*100+item1.day;
  date2=item2.year*10000+item2.month*100+item2.day;

  if(date1>date2 || (date1==date2 && item1.hour*100+item1.minute>=item2.hour*100+item2.minute))
    return 1;
  else
    return 0;
}
