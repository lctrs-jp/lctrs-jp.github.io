#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define LEN 50

void load(ATTEND data[],int size,char *argv[1],char *argv[2],char *argv[3]);
void print(ATTEND data[]);
void marking(int a,int b,char m);

struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

typedef struct attendance ATTEND;

int main(int argc,char *argv[]){

  ATTEND item[MAX];
  int size;

  if(argc != 4)
    {
      printf("三人の都合のファイルを入力してください。");
      exit(1);
    }

  for(int i=0;i<MAX;i++)
    load(item[i],size,argv[1],argv[2],argv[3]);

  printf("date\tAlice\tBob\tCarol\t");
  printf("-----------------------------------------------");

  for(int j=0;j<size;j++)
    print(item[i]);

  printf("-----------------------------------------------");

  return 0;
}

void load(ATTEND data[],int size,char *argv[1],char *argv[2],char *argv[3]){
  char buf[LEN],mark;
  int len,d,a,datecheck;
  FILE *fp[3];

  for(int i=0;i<3;i++)
    if((fp[i]=fopen(argv[i+1],"r"))==NULL){
      printf("ファイルの中身が空です。");
      exit(1);
    }

  for(int j=0;j<3;j++){
    while(fgets(buf,LEN,fp[i])){
      len=strlen(buf);
      if(len>0 && buf[len-1]=='\n')
	buf[len-1]='\0';
      sscanf(buf,"%d %s",d,mark);
      for(int k=0;k<MAX;k++)
	if(d==data[k].date)
	  marking(j,k,mark);
	else{
	  for(int l=0;data[l].date != 0;)
	    l++;
	  l++;
	  marking(j,l,mark)
	    }
    }
  }
  return;
}

void marking(int a, int b, char m){
  switch(a){
  case 0: 
    data[b].alice=m;
    break;
  case 1:
    data[b].bob=m;
    break;
  case 2:
    data[b].carol=m;
    break;
  }

  if(m=="o")
    data[b].ok=data[b].ok+1;
  else if(m=="x")
    data[b].unfixed=data[b].unfixed+1;

  return;
}

void print(ATTEND data[]){
  int n,day,month,year;
    
  for(int i=0;data[i].date != 0;i++){
    n=data[i].date;
    day=n%100;
    month=(n/100)%100;
    year=n/10000;
    
    printf("%d/%d/%d\t%c\t%c\t%c\n",year,month,day,data[i].alice,data[i].bob,data[i],carol,data[i].ok,data[i].unfixed);
  }
  
  printf("--------------------------------------------------");
    
  for(int j=0;data[j].date != 0;j++)
    printf("[ok:%d, ?:%d]",data[j].ok,data[j].unfixed);
  
  return;
}
