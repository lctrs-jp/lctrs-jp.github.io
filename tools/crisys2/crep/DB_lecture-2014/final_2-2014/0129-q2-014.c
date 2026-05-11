#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 100

struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
};

typedef struct attendance ATTENDANCE;
void print(ATTENDANCE d[MAX],int size,ATTENDANCE avg);
int load(ATTENDANCE d[MAX],char *filename,int size);
ATTENDANCE sum(ATTENDANCE d[MAX],int size);
void sort(ATTENDANCE item[MAX],int count);

int main(int argc,char *argv[])
{
ATTENDANCE dates[MAX], avg;
int i,size;
 if(argc<2){
   printf("Usage: %s filename1 ... filename2\n", argv[0] );
   exit(1);
 }

for (i=1;i < argc; i++){//データの読み込み
   size=load(dates,argv[i],size);
 }
avg = sum(dates,size);
 sort(dates,size);
 print(dates,size,avg);
return 0;
}
int load(ATTENDANCE d[MAX],char *filename,int size)
{
FILE *fp;
 char buf[LEN],names[LEN];
char date[50];
int len,id,score,i;

if ((fp=fopen(filename,"r"))== NULL) {
  printf("ファイル%sのオープンに失敗しました", filename);
  exit(1);
  }
 fgets(buf,LEN,fp);
 len= strlen(buf);
 if(len>0&&buf[len-1]=='\n')
   buf[len-1]= '\0';
 strcpy(names,&buf[1]);
  while (fgets(buf,LEN,fp)!= NULL){
   len= strlen(buf);
 if(len>0&&buf[len-1]=='\n')
  buf[len-1]= '\0';
 sscanf(buf,"%s %d",date,&score);
for (i= 0;i<size;i++){
  if (strcmp(date,d[i].date)==0){
 id=i;
 break;
  }
 }
if (i==size){
  strcpy(d[i].date,date);
id=size;
 size++;
 }

if (strcmp(names,"Alice")==0)
 d[id].Alice=score;
 else if (strcmp(names,"Bob")==0)
 d[id].Bob= score;
 else if (strcmp(names,"Carol")==0)
 d[id].Carol= score;
 else printf("Wrong names error:%s\n",names);
  }
 return size;
}


void print(ATTENDANCE d[MAX],int size,ATTENDANCE avg)
{
int i;
 printf("date\tAlice\tBob\tCarol\t");
 printf("--------------------------------------\n"); 
  
  for (i= 0;i< size;i++){
  printf("%s\t%3d\t%3d\t%3d\t%3d\n",
	 d[i].date,d[i].Alice,d[i].Bob,d[i].Carol);
 }
 printf("--------------------------------------\n");
 
}
