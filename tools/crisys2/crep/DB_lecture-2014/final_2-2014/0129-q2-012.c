#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 273
struct attendance{
  char date[9];//日にち
  char alice;//Aliceの都合
  char bob;//Bobの都合
  char carol;//Carolの都合
  int ok;//参加可能な人数
  int unfixed;//参加未定（?）の人数
};

typedef struct attendance ATD;

void print(ATD d[MAX], int size );
int load(ATD d[MAX], char *filename, int size );

int main(int argc, char *argv[])
{
  ATD member[MAX];
  int i, size;
  
  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }
  
  for (i = 1 ; i < argc ; i++ ){
    size = load(member, argv[i], size);
  }
  print(member, size );
  
  return 0;
}

int load(ATD d[MAX], char *filename, int size )
{
  FILE *fp;
  char buf[LEN],name[LEN];
  char ox, date[9];
  int len, i ;
  
  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);
  
  size = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    sscanf(buf,"%s %c", date, &ox );
    for( i = 0 ; i < size ; i++ ){
      if(strcmp(date, d[i].date) == 0){
	break;
      }
    }
    if ( i == size ){// 新規の予定の追加
      strcpy(d[i].date, date);
      size++;
    }
     
    if(strcmp(name,"Alice") == 0)
      d[i].alice = ox;
    else if(strcmp(name,"Bob") == 0)
      d[i].bob = ox;
    else if(strcmp(name,"Carol") == 0)
      d[i].carol = ox;
    else
      printf("Wrong name error: %s\n", date );
    
  }
  
  return size; 
}
  
void print(ATD d[MAX], int size )
{
  int i;
  printf("date\tAlice\tBob\tCarol\t\n");
  printf("--------------------------------------\n");
  for( i = 0 ; i < size ; i++ ){
    printf("%s\t%c\t%c\t%c\t\n",
	   d[i].date, d[i].alice, d[i].bob, d[i].carol );
  }
  printf("--------------------------------------\n");
}   

  
