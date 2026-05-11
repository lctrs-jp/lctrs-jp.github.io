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
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTENDANCE;

void print(ATTENDANCE d[MAX], int size);
int load(ATTENDANCE d[MAX], char *filename, int size);

int main(int argc, char *argv[])
{
  ATTENDANCE date[MAX];
  int i,size;

  if(argc < 2){
    printf("USAGE: %S filename1 ... filename2/n", argv[0]);
    exit(1);
  }
  for (i = 1;i < argc;i++){
    size = load(date,argv[i],size);
  }
  return 0;
}

int load(ATTENDANCE d[MAX], char *filename,int size)
{
  FILE *fp;
  char buf[LEN], person[LEN], capable;
  int len, n, year, month, day, i;

  if ((fp = fopen (filename, "r")) == NULL){
    printf ("ファイル%Sのオープンに失敗しました", filename);
    exit (1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(person,&buf[1]);
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';

    sscanf(buf, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    if (strcmp(person, "Alice")==0)
      d[day].alice = capable;
    else if (strcmp(person, "Bob")==0)
      d[day].bob = capable;
    else if (strcmp(person, "Carol")==0)
      d[day].carol = capable;
    else
      printf("Wrong person error: %s\n", person);
  }
  return size;
}

void print(ATTENDANCE d[MAX], int size)
{
  int i, day, month, year;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------------------\n");
  for (i = 0;i < size;i++){
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
    	   year, month, day,
	   d[i].alice, d[i].bob, d[i].carol,
	   d[i].ok, d[i].unfixed );
  }
  printf("--------------------------------------------------\n");
}
