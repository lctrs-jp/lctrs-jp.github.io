#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 273
struct attendance {
  char date;
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};
typedef struct attendance ATTEND;

void print(ATTEND d[MAX], int size);
int load(ATTEND d[MAX],char *filename);

int main(int argc, char *argv[]){
  struct attendance item[MAX];
  int n,year,month,day,size,i;

  if(argc< 2 ){
    printf("Usage: %s filename1...filename2\n",argv[0]);
    exit(1);
  }
  for (i=1;i < argc;i++){
    size = load(item,argv[i]);
  }
  print(item,size);
  return 0;
}
int load(ATTEND d[MAX],char *filename)
{
  FILE *fp;
  char buf[LEN],name[LEN];
  int len,size,id;
  char attend,day;
  id = 0;

  if((fp = fopen(filename,"r"))==NULL){
    printf("ファイル %s のオープンに失敗しました",filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);
  size = 0;
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len >0 && buf[len-1]=='\n')
      buf[len-1]= '\0';
    sscanf(buf,"%c %c",&day,&attend);
    
    size++;
    d[id].date = day;
    if(strcmp(name,"Alice")==0)
      d[id].alice = attend;
    else if (strcmp(name,"Bob")==0)
      d[id].bob = attend;
    else if(strcmp(name,"Carol")==0)
      d[id].carol = attend;
    else
      printf("Wrong name error: %s\n",name);
    id++;
    }
  return size;
}
void print(ATTEND d[MAX],int size)
{
  int n,year,month,day,i;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("____________________________________\n");
  for(i=0;i<size;i++){
    sscanf(d[i].date,"%d",&n);
    day = n%10;month = (n/100)%100;year = n/10000;
    
    printf("&4d/%2d/%2d\t%c\t%c\t%c\t\n",
	   year,month,day,
	   d[i].alice,d[i].bob,d[i].carol);
  }
  printf("____________________________________\n");
}
