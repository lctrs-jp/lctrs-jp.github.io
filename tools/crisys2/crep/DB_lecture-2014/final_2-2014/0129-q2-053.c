#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 30

struct attendance {
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

typedef struct attendance A;

void print(A a[MAX],int size);
int load(A a[MAX],char *filename,int size);


int main(int argc, char *argv[])
{
  A date[MAX]; 
  int i,size ;
  
  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for (i = 1;i < argc;i++){//データの読み込み
    size = load(date,argv[i],size);
  }  
  
  print(date,size);
  return 0;
}

int load(A a[MAX],char *filename,int size)
{
  FILE *fp;
  char buf[LEN],name[LEN];
  char date[9];
  int len,id,pre,i;
  
  if  ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました", filename);
    exit (1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len >0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);

  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0'; 
    sscanf(buf,"%s %d", date, &pre);
    for (i = 0;i < size;i++){
      if (strcmp(date,a[i].date)==0){
	id = i;
	break;
      }
    }
    if (i == size){// 新規の日付の追加
      strcpy(a[i].date,date);
      id = size;
      size++;
    }

    if (strcmp(name,"alice")==0)
      a[id].alice = pre;
    else if (strcmp(name,"bob")==0)
      a[id].bob = pre;
    else if (strcmp(name,"carol")==0)
      a[id].carol = pre;
    else
      printf("Wrong name error: %s\n",name);
  }
  return size; 
}



void print(A a[MAX],int size)
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
  for (i = 0;i < size;i++){
    printf("%s\t%s\t%s\t%s\n",
	   a[i].date,a[i].alice,a[i].bob,
	   a[i].carol);
  }
  printf("--------------------------------------\n");
  
}

