#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 270
struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

typedef struct attendance ATTENDANCE;

int load(ATTENDANCE d[MAX], char *filename);

int main(int argc, char *argv[]){

  ATTENDANCE students[MAX], avg;
  int i,size;

  if(argc < 2){
    printf("Usage: %s filename1 ... filename2\n",argv[0]);
    exit(1);
  }
  for (i = 1; i < argc; i++){
    size = load(students,argv[i]);
  }
 printf(students,size);
  return 0;
}

int load (ATTENDANCE d[MAX],char *filename)
{
  FILE *fp;
  char buf[LEN],a,b,c,o,x,'?';
  int len,D=20150127,result,size,subject,z;

  struct attendance item = {"z", a,b,c,1,1};
  int n, year,month,day;

  if((fp = fopen(filename, "r"))== NULL){
    printf("ファイル%sのオープンに失敗しました", filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if (len > 0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(subject,&buf[1]);
  size = 0;
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d %d", &D, &result );
    D = D + 1;
    size++;
    if (strcmp(a,o) == 0)
      d[D].o = result;
    else if (strcmp(a,?) == 0)
      d[D].? = result;
    else if (strcmp(a,x) == 0)
      d[D].x = result;
    else
      printf ("Wrong subject error: %s\n", subject);
  }

  printf(item.date, "%d", &n);
  day = n % 100;month = (n/100)%100; year = n/10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",item.alice,item.bob,item.carol,item.ok,item.unfixed);

  return size;
}
