#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define LEN 256

int write(char buf[], char *out[]);

struct event {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[LEN];
};

int main(int argc, char *argv[])
{
  struct event item[MAX];
  int i, j, k=0,n,d,t,len;;
  FILE *fp;
  char *out[MAX];
  char buf[LEN]; 

  if( argc < 2 ){
    printf("使用法が間違っています。\n");
    exit(1);
  }

  k=0;
  for(i=1;i<argc;i++){
    if((fp = fopen(argv[i],"rb")) == NULL ){
      printf("ファイルを開くことはできません。\n");
      exit(1);
    }

    while(fgets(buf,LEN,fp)!=NULL ){
      len=strlen(buf);
      if(len>0&& buf[len-1]=='\n'){
	buf[len-1]='\0';
      }
      n=write(buf, out);
      if(n==0){
	continue;
      }
	  else if(n<3){
	printf("読み込みエラー\n");
      }
	  else{
	d=atoi(out[0]);
	item[k].year=d%10000;
	item[k].month=d%10000;
	item[k].day=d/100;
	t=atoi(out[1]);
	item[k].hour=t%100;
	item[k].minute=t/100;
	strncpy(item[k].content,out[2],LEN);
	k++;
      }
    }
    fclose(fp);
  }

  for(i=0;i<k;i++){
    printf("%4d/%2d/%2d %2d:%.2d %s\n",
	   item[i].year,item[i].month,item[i].day,item[i].hour,  
	   item[i].minute,item[i].content);
  }
  return 0;
}

int write(char buf[],char *out[])
{
  int n;
  char *p = buf;

  for(p=buf;*p!='\0';p++){
    if((p==buf||*(p-1)==' ')&&*p!=' '){
      out[n]=p;
      n++;
    }
  }
  return n;
}
