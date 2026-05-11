#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 273
#define MAX 30

struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};
typedef struct attendance ATTENDANCE;

void print(ATTENDANCE d[MAX],int size, ATTENDANCE item);
int load(ATTENDANCE d[MAX], char *filename);


int main(int argc, char *argv[])
{
  ATTENDANCE date [MAX],item;
  int i, size;

  if(argc < 2){
    printf("Usage: %s filename1...filename2\n",argv[0]);
    exit(1); 
  }
  for (i=1; i<argc; i++){
    size = load(date, argv[i]);
  }
  print(date,size,item);
  return 0;
  }    


int load(ATTENDANCE d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN], reaction[LEN];
  int len,size,attendance,id;

  if ((fp = fopen (filename, "r")) == NULL){
    printf ("ファイル　%s　のオープンに失敗しました", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if(len > 0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(reaction, &buf[1]);
  size = 0;
 
  while(fgets(buf, LEN, fp)!= NULL){
    len =strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf, "%d", &attendance);
    size++;

    if(strcmp(reaction,"alice") == 0)
      d[id].alice = attendance;
    else if(strcmp(reaction,"bob") == 0)
      d[id].bob = attendance;
    else if(strcmp(reaction,"carol") == 0)
      d[id].carol = attendance;
    else 
      printf("Wrong attendance error: %s\n", reaction);
  }
  return size;
}  


void print(ATTENDANCE d[MAX], int size, ATTENDANCE item)
{
  int i,year,month,day,n;
  printf("date\tAlice\tBob\tCarol\n");
  printf(item.date, "%d",&n);
  day=n%100; month=(n/100)%100; year=n/10000;   

  for(i = 0; i < size; i++){
    printf("%8d\t%d\t%d\t%d\n",i+1,d[i].alice,d[i].bob,d[i].carol);
  }
  printf("-------------------------------------------\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",year,month,day,item.alice,item.bob,item.carol,item.ok,item.unfixed);
} 
