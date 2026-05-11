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
void sum(AT d[MAX],int size);
void sort(AT d[MAX],int size);
void sortpri(AT d[MAX],int size);
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
  sum(tugou,size);
  print(tugou,size);
  sort(tugou,size);
  sortpri(tugou,size);
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

void sum(AT d[MAX],int size)
{
  int i;
  for(i=0;i<size;i++){
    d[i].ok=0;
    d[i].unfixed=0;
    if(d[i].alice=='o')
      d[i].ok++;
    else if(d[i].alice=='?')
      d[i].unfixed++;
    if(d[i].bob=='o')
      d[i].ok++;
    else if(d[i].bob=='?')
      d[i].unfixed++; 
    if(d[i].carol=='o')
      d[i].ok++;
    else if(d[i].carol=='?')
      d[i].unfixed++;
  }
  return;
}


void sort(AT d[MAX], int size)
{
  int a,b;
  AT t;
  for(a=1;a<size;a++)
    for(b=size-1;b>=a;b--){
      if(d[b-1].ok<d[b].ok){
	t=d[b-1];
	d[b-1]=d[b];
	d[b]=t;
      }
    }
  return;
}

void print(AT d[MAX],int size)
{
  int i,day,month,year,n,j;
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
  printf("___________________________________________\n");
  for(j=0;j<size;j++){
    sscanf(d[j].date,"%d",&n);
    day=n%100;
    month=(n/100)%100;
    year=n/10000;
    printf("%4d/%2d/%2d\t[ok:%d,?:%d]\n",
	   year,month,day,
	   d[j].ok,d[j].unfixed);
  }
  return ;
}

void sortpri(AT d[MAX],int size)
{
  int i,day,month,year,n,j; for(j=0;j<size;j++){
    sscanf(d[j].date,"%d",&n);
    day=n%100;
    month=(n/100)%100;
    year=n/10000;
    printf("%4d/%2d/%2d\t[ok:%d,?:%d]\n",
           year,month,day,
           d[j].ok,d[j].unfixed);}

return}

