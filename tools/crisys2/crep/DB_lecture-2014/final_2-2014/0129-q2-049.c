#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30

struct attendance {
  char date[20]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};
typedef struct attendance ATTENDANCE;

 
int main(int argc, char *argv[])
{
  ATTENDANCE attendance[100];
  FILE *fp[3];
  int i,j,size;
  int n,year, month, day;
  int counta,countb;
  counta=countb=0;
  char buf[273];
  char buf2[273];
  char buf3[273];
  char name[50];
  int len;

  if(argc<2){
    printf("Error");
    exit(1);
  }

  fp[0]=fopen(argv[1],"r");
  fp[1]=fopen(argv[2],"r");
  fp[2]=fopen(argv[3],"r");
  if((fp[0])==NULL&&fp[1]==NULL&&fp[2]==NULL){
    printf("Error");
    exit(1);
  }

  fgets(buf,273,fp[0]);
  len=strlen(buf);
  if(len>0&&buf[len-1]=='\n')
  buf[len-1]='\0';
  while(fgets(buf,273,fp[0])!=NULL){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
      sscanf(buf,"%c %c",attendance[i].date,&attendance[i].alice);
    i++;
  }
  
  

  i=0;
  fgets(buf2,273,fp[1]);
  len=strlen(buf2);
  if(len>0&&buf2[len-1]=='\n')
    buf[len-1]='\0';
  strcpy(name,&buf2[1]);
  while(fgets(buf2,273,fp[1])!=NULL){
    len=strlen(buf2);
    if(len>0&&buf2[len-1]=='\n')
      buf2[len-1]='\0';
    sscanf(buf,"%c %c",attendance[i].date,&attendance[i].bob);
    i++;
  }
  
  

  i=0;
  fgets(buf3,273,fp[2]);
  len=strlen(buf3);
  if(len>0&&buf3[len-1]=='\n')
    buf3[len-1]='\0';
  strcpy(name,&buf3[1]);
  while(fgets(buf3,273,fp[2])!=NULL){
    len=strlen(buf3);
    if(len>0&&buf3[len-1]=='\n')
      buf3[len-1]='\0';
    sscanf(buf3,"%c %c",attendance[i].date,&attendance[i].carol);
    i++;
  }
  
   
  printf("date\t\tAlice\tBob\tCarol\n");
  
  for(j=0;j<i;j++){
  sscanf( attendance[j].date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;
  if(attendance[j].alice=o){
    counta++;
  }
  else if(attendance[j].alice=?){
    countb++;
  }
  if(attendance[j].bob=o){
    countb++;
  }
  else if(attendance[j].bob=?){
    countb++;
  }
  if(attendance[j].carol=o){
    counta++;
  }
  else if(attendance[j].carol=?){
    countb++;
  }
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
         year, month, day,
         attendance[j].alice, attendance[j].bob, attendance[j].carol,
         counta, countb );
  }
  
  fclose(fp[0]);
  fclose(fp[1]);
  fclose(fp[2]);
  return 0;
}

