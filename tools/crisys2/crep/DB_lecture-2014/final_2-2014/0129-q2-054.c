#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256
#define MAX 30

struct attendance {
  int date;     // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
  int day;
  int month;
  int year;
};

typedef struct attendance ATTEND;

void print(ATTEND d[MAX], int size);
int load(ATTEND d[MAX], char *filename);

int main(int argc, char *argv[])
{
  ATTEND name[MAX];
  int i, size;

  if ( argc != 4 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
  }

  for (i = 1 ; i < argc ; i++ ){
    size = load(name, argv[i]);
  }
  print(name, size);

  return 0;
}

int load(ATTEND d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN], name[LEN], w;
  int len, size;


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
    sscanf(buf,"%d %c", &d[size].date, &w);


    if(strcmp(name,"Alice") == 0)/* 文字列が同じかどうか */
      d[size].alice = w;
    else if(strcmp(name,"Bob") == 0)
      d[size].bob = w;
    else if(strcmp(name,"Carol") == 0)
      d[size].carol = w;
    else
      printf("Wrong subject error: %s\n", name );

    size++;
  }

  return size; // データの個数を返す
}


void print(ATTEND d[MAX], int size)
{
  int i;

  printf("date\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");

  for( i = 0 ; i < size ; i++ ){
    d[i].day = d[i].date % 100;
	d[i].month = (d[i].date / 100) % 100;
    d[i].year = d[i].date / 10000;


    printf("%4d/ %d/%2d\t%c\t%c\t%c\n",
           d[i].year, d[i].month, d[i].day,
           d[i].alice, d[i].bob, d[i].carol );
  }
  printf("--------------------------------------\n");
}
