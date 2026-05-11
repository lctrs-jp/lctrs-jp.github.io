#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 273

struct attendance {
   char date[9]; // 日にち
   char alice;   // Aliceの都合
   char bob;     // Bobの都合
   char carol;   // Carolの都合
   int ok;       // 参加可能な人数
   int unfixed;  // 参加未定（?）の;
};

typedef struct attendance ATD;
void print(ATD d[MAX],int size);
ATD trance(ATD d[MAX],int size);
int load(ATD d[MAX],char *filename);

int main(int argc, char *argv[])
 {
   ATD member[MAX];
   ATD date;
   int i,size=0; 
      /*引数の確認*/
    if (argc <2)
	{
	  printf("Usage: %s <filename1,,,>\n", argv[0]);
	  exit(1);
	}
    for(i=1;i<argc;i++){
      size = load(member,argv[i],size);//人数
    }
    trn=trance(date,size);//読みこんだ日付を変形
    print(member,size,trn);//表示
    return 0;
 }
    

int load(ATD d[MAX],char *filename)
{
  FILE *fp;
  char buf[LEN];
  char date[8],poss;
  int len,size;

  if((fp=fopen(filename,"r"))==NULL){
     printf("ファイル%sのオープンに失敗しました",filename);
     exit(1);
  }
  fgets(buf,LEN,fp);
  len=strlen(buf);
  if(len >0 && buf[len-1]=='\n')
    buf[len-1]='\0';
  strcpy(name,&buf[1]);
  size=0;
  while(fgets(buf,LEN,fp)!=NULL){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
    sscanf(buf,"%s %s",&date,&poss);
    size++; 
    if (strcmp(member,"Alice")==0)
       d[].alice=poss;
    else if(strcmp(subject,"Bob")==0)
       d[id].bob=poss;
    else if(strcmp(subject,"Carol")==0)
       d[id].carol=poss;
    else
       printf("Wrong person error:%s\n",subject);
  }
   return size;

  void print(ATD d[MAX], int size, ATD trn)
  {
    int i;
    printf("date\tAlice\tBob\Carol\n");
    printf("-----------------------------------\n");
    for(i=0;i<size;i++){
      printf("%s\t%3d\t%3d\t%3d\t%3d\t\n"
	     ,d[i].date,d[i].alice,d[i].bob,d[i].carol);
    }
    printf("-----------------------------------\n");
  }
