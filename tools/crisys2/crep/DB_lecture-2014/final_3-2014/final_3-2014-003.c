#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 273

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTENDANCE;
void print(ATTENDANCE d[MAX],int size,ATTENDANCE avg);
int load(ATTENDANCE d[MAX],char *filename,int size);
int main(int argc, char *argv[])
{
  ATTENDANCE friends[MAX], avg;
  int i,size;

  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }
  for (i = 1;i < argc;i++){//データの読み込み
    size = load(friends,argv[i],size);
  }
  print(friends,size,avg);
  return 0;
}
int load(ATTENDANCE d[MAX],char *filename,int size)
{
  FILE *fp;
  char buf[LEN],friends[LEN];
  char date[50];
  int len,id,schedule,i;

  if  ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました", filename);
    exit (1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(friends,&buf[1]);
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d %s", date, &schedule);
    for (i = 0;i < size;i++){
      if (strcmp(date,d[i].date)==0){
        id = i;
        break;
      }
    }
    if (i == size){// 新規の名前の追加
      strcpy(d[i].date,date);
      id = size;
      size++;
    }
    if (strcmp(friends,"alice")==0)
      d[id].alice = schedule;
    else if (strcmp(friends,"bob")==0)
      d[id].bob = schedule;
    else if (strcmp(friends,"carol")==0)
      d[id].carol = schedule;
    else
      printf("Wrong friends error: %s\n",friends);
  }
  return size; // データの個数を返す
}

void print(ATTENDANCE d[MAX],int size,ATTENDANCE avg)
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
  for (i = 0;i < size;i++){
    printf("%4d/%d/%2d\t%s\t%s\t%s\n",
           d[i].date,d[i].alice,
           d[i].bob,d[i].carol);
    printf("--------------------------------------\n");
  }
}

