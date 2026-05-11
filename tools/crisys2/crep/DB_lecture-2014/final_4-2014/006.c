#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 100

struct  attendance {
  int date; 
  char alice[1];   
  char bob[1];     
  char carol[1];   
  int ok; 
  int unfixed; 
};

typedef struct attendance AT;

void print(AT d[MAX], int size);
int load(AT d[MAX], char *filename, int size);
void sort(SCORE item[MAX], int count)
int main(int argc, char *argv[])
{
  AT students[MAX];
  int i, size;
  
  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for(i = 1 ; i < argc ; i++ ){ 
    size = load(students, argv[i], size);
  }

  print(students, size);
    
  return 0;
}

int load(AT d[MAX], char *filename, int size)
{
  FILE *fp;
  char buf[LEN],nam[LEN];
  int  date;
  int len, id, i;
  char sanka[1];

  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(nam, &buf[1]);

  size = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    sscanf(buf,"%d %s", &date, sanka );
    for( i = 0 ; i < size ; i++ ){
      if(d[i].date == date){
	id = i;
	break;
      }
    }
    if(i == size){
      d[i].date = date;
      id = size;
      size++;
    }

      if(strcmp(nam,"Alice") == 0)
	strcpy(d[id].alice, sanka);
      else if(strcmp(nam,"Bob") == 0)
	strcpy(d[id].bob, sanka);
      else if(strcmp(nam,"Carol") == 0)
	strcpy(d[id].carol, sanka);
      else
	printf("Wrong name error: %s\n", nam );
  }

  return size;

}

void print(AT d[MAX], int size)
{
  int i;
  int year, month, day;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
 
  for( i = 0 ; i < size ; i++ ){

    day = d[i].date % 100;
    month = (d[i].date / 100) % 100;
    year = d[i].date / 10000;
    printf("%4d/%2d/%2d\t%1c\t%1c\t%1c\n",
	   year,month,day, d[i].alice, d[i].bob, d[i].carol );
  }
  printf("--------------------------------------\n");
  
}
void sort(SCORE item[MAX], int count)
{
  int a,b;
  SCORE t;
  for( a = 1 ; a < count ; a++)
    for ( b = count-1 ; b >= a ; b-- ){
      if( item[b-1].total < item[b].total ){
        t = item[b-1];
        item[b-1] = item[b];
        item[b] = t;
      }
    }
}
