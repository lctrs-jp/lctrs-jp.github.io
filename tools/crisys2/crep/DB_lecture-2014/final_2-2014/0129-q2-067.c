#include <stdio.h>
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

typedef struct attendance AT;

void print(AT d[MAX],int size);
int load(AT d[MAX],char *filename, int size);
void sort(AT item[MAX],int count);


int main(int argc, char argv[])
{
  int i;
  int size;
  AT item[MAX];
  if( argc < 4 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for (i = 1;i < argc;i++){//データの読み込み
    size = load(item,argv[i],size);
  }
    sort(item,size);
    print(item,size);
    return 0;
}




int load(AT d[MAX],char *filename)
{
  FILE *fp;
  char buf[LEN],subject[LEN];
  char name[50];
  int len,date,i,size,j;
  char attend;
  
  if  ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました", filename);
    exit (1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(subject,&buf[1]);

  size = 0;
  j = 0;
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0'; 
    sscanf(buf,"%d %c", &date, &attend);
    id = id - 1;
    size++;
       
    d[j].date = date
      if (strcmp(subject,"Alice")==0)
	d[j].alice = attend;
      else if (strcmp(subject,"Bob")==0)
	d[j].bob = attend;
      else if (strcmp(subject,"Carol")==0)
	d[j].carol = attend;
      else
	printf("Wrong subject error: %s\n",subject);
    }
    return size; // データの個数を返す
  }



  return 0;
}

void sort(AT item[MAX],int count)
{
  int a,b;
  AT t;
  for (a = 1; a < count; a++)
    for (b = count-1; b >= a; b--){
      if (item[b-1].date < item[b].date){
        t = item[b-1];
        item[b-1] = item[b];
        item[b] = t;
      }
    }
}


void print(AT item[MAX],int size)
{
  int year,month,day;
  year = month = day = 0;
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  printf("--------------------------------\n");
  for (i = 0;i < size;i++){
    year = (item[i].date)%100;
    month = ((item[i].date)-100)%100;
    day = (item[i].date)/%10000;

  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year,month,day,item[i].alice,item[i].bob,item[i].carol);
  }
}
