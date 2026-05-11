#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 100

struct attendance {
  char date[9]; // 日にち
  char alice;   // aliceの都合
  char bob;
  char carol;
  int ok;
  int unfixed;
};

typedef struct attendance ATTENDANCE;
int load(ATTENDANCE d[MAX], char *filename,int size);


int main(int argc, char *argv[])
{
  ATTENDANCE number[MAX], avg;
  int i,size;

  if(argc < 2){
    printf("Usage: %s", argv[0]);
    exit(1);
  }
  for ( i= 1; i < argc; i++){
    size = load(number, argv[i],size);
  }



  return 0;

}

int load(ATTENDANCE d[MAX], char *filename, int size)
{
  FILE *fp;
  char buf[LEN],name[LEN];
  int len, time;
  char point[10];
  if ((fp = fopen (filename, "r")) == NULL){
    printf("ファイル%s のオープンに失敗しました", filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);

  while (fgets(buf,LEN,fp) !=NULL){
    len = strlen(buf);
    if( len>0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d %s", &time, point);

    printf("%d %s\n", time, point);
  }
  return size;
}

