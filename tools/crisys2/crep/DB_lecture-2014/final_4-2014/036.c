#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTENDANCE;

int load(ATTENDANCE d[MAX],char *filename)//load関数
{
  FILE *fp;
  char buf[LEN],person[LEN];
  char name[50];
  int len,date,attendance,size,n;
  if ((fp=fopen(filename,"r"))==NULL){
    printf("ファイル%sのオープンに失敗しました",filename);
    exit(1);
  }
  fgets(buf,LEN,fp);
  len=strlen(buf);
  if(len>0 && buf[len-1]=='\n')
    buf[len-1]='\0';
  strcpy(person,&buf[1]);
  size = 0;
  while(fgets(buf,LEN,fp)!=NULL){
    len=strlen(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d%d",&date,&attendance);
    n = date;
    day = n%10; month = (n/100)%100; year = n/10000;
    size++;
  }
  return size;//データの個数を返す
}

void print(ATTENDANCE d[MAX],int size)//print関数
{
  int i;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
  for(i=0;i<size;i++){
    printf("%s\t%3d\t%3d\t%3d\t%3d\n",
	   d[i].date,d[i].attendance.Alice,d[i].attendance.Bob,
	   d[i].attendance.Carol);
  }
  printf("--------------------------------------\n");
}

//メイン関数
int main(int argc, char *argv[])
{
  ATTENDANCE students[MAX], avg;
  int i,size,year,month,day,item;

  if(argc < 2){
    printf("Usage: %s filename1...filename2\n",argv[0]);
  }
  for (i = 1;i<argc;i++){
    size = load(students,argv[i]);
  }
  print(students,size);
  return 0;
}
