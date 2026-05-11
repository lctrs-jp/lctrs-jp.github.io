#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 100

struct attendance {
  char name[50];
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数

};

typedef struct attendance ATTENDANCE;

void print(ATTENDANCE d[MAX], int size, ATTENDANCE avg);
int load(ATTENDANCE d[MAX], char *filename ,int size);
ATTENDANCE sum(ATTENDANCE d[MAX], int size);
void print1(ATTENDANCE d[MAX], int size );
void sort(ATTENDANCE item[MAX],int count);

int main(int argc, char *argv[])
{
  ATTENDANCE students[MAX], avg;
  int i, size;

  if( argc < 4 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }
  for (i = 1 ; i < argc ; i++ ){
    size = load(students, argv[i], size);
  }

  print(students, size);
  void print1(ATTENDANCE d[MAX], int size );
  sort(students,size);
  return 0;
}

int load(ATTENDANCE d[MAX], char *filename,int size)
{
  FILE *fp;
  char buf[LEN],subject[LEN];
  char  name[50];
  int len, id, score, size, i;

  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(subject, &buf[1]);

  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0'; 
    sscanf(buf,"%s %d", name, &attendance );
    for( i = 0 ; i < size ; i++ ){
      if(strcmp(name, d[i].name) == 0){
	id = i;
	break;
      }
    }
    if ( i == size ){// 新規の名前の追加
      strcpy(d[i].name, name);
      id = size;
      size++;
    }

    if(strcmp(subject,"Alice") == 0)
      d[id].alice = attendance;
    else if(strcmp(subject,"Bob") == 0)
      d[id].bob = attendance;
    else if(strcmp(subject,"Carol") == 0)
      d[id].carol = attendance;
    else
      printf("Wrong subject error: %s\n", subject );
  }

  return size; // データの個数を返す
}
ATTENDANCE sum(ATTENDANCE d[MAX], int size)
/* 合計を計算する */
{
  int i, math, japanese, english, total;
  ATTENDANCE avg;

  /* 各個人ごとの合計参加可能を計算 */
  for( i = 0 ; i < size ; i++ ){
    d[i].total = d[i].ok;
  }


void print(ATTENDANCE d[MAX], int size )
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  for( i = 0 ; i < size ; i++ ){
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	   i+1, d[i]. year, d[i].month, d[i].day,
	   d[i].alice, d[i].bob, d[i].carol,
	   d[i].ok, d[i].unfixed );
  }
  printf("--------------------------------------\n");

}
void print1(ATTENDANCE d[MAX], int size )
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  for( i = 0 ; i < size ; i++ ){
    printf("%4d/%2d/%2d\t%d\n",
	   i+1, d[i]. year, d[i].month, d[i].day,
	   d[i].total);
  }
  printf("--------------------------------------\n");

}

void sort(ATTENDANCE item[MAX], int count)
{
  int a,b;
  ATTENDANCE t;
  for( a = 1 ; a < count ; a++)
    for ( b = count-1 ; b >= a ; b-- ){
      if( item[b-1].ok < item[b].ok ){
        t = item[b-1];
        item[b-1] = item[b];
        item[b] = t;
      }
    }
}
