#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 273

struct attendance {
  char date[9];//日にち
  char alice;//アリスさんの都合
  char bob;//ボブさん
  char carol;//キャロルさん
  int ok; //いける確定
  int unfixed;//不明
};

typedef struct attendance AT;
int laod(AT d[MAX],int size,char *filename);
void print(AT d[MAX],int size);
int main(int argc,char *argv[]){
  AT tugou[MAX];
  int size,i;

  if(argc <3){
    printf("三人の名前を入力してください\n");
    exit(1);
    }

  for(i=1;i<=3;i++)
   size=load(tugou,size,argv[i]);
  print(tugou,size);

  return 0;
}

int load(AT d[MAX],int size,char *filename)
{
  FILE *fp ;
  char buf[LEN],j,day[9],person[LEN];
  int len,n,i;

  if ((fp=fopen(filename, "r")) == NULL) {
    printf ("ファイル%sのオープンに失敗しました",filename );
    exit (1);
  }

  fgets ( buf,LEN,fp );
  len=strlen (buf);
  if(len>0 &&buf[len-1]=='\n')
    buf [len-1] = '\0';
  strcpy(person,&buf[1]);

  while(fgets(buf,LEN,fp)!=NULL){
    len=strlen (buf );
    if(len>0 &&buf[len-1]=='\n')
      buf [len-1] = '\0';
    sscanf(buf,"%s %c",day,&j);

    for(i=0;i<size;i++)
      if(strcmp(day,d[i].date)==0){
	n=i;
	break;
      }

    if(i==size){
      strcpy(d[i].date,day);
      n=size;
      size++;
}
    if(strcmp(person,"Alice")==0)
      d[n].alice=j;
    else if(strcmp(person,"Bob")==0)
      d[n].bob=j;
    else if(strcmp(person,"Carol")==0)
      d[n].carol=j;
    else
      printf("error");
  }
    return size;
}
void print(AT d[MAX],int size)
{
  int i,day,month,year,n;
  printf("date\tAlice\tBob\tCarol\n");
  printf("____________________________________________\n");
  for(i=0;i<size;i++){  
  sscanf(d[i].date,"%d",&n);
  day=n%100;
  month=(n/100)%100; 
  year=n/10000;
  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 year,month,day,
	 d[i].alice,d[i].bob,d[i].carol);
  }
  printf("___________________________________________");
  return ;
}
