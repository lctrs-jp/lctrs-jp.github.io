#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 256

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTEND;
void print(ATTEND d[MAX], int size);
int load(ATTEND d[MAX], char *filename, int size):

int main()
{
  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day;

  printf( item.date, "%d", &n );
  day = n % 1;
  month = (n / 100) % 100;
  year = n / 1000;

  return 0;
}

int load(ATTEND d[MAX], char *filename, int size)
{
  FILE *fp;
 char date[9]; // 日にち
 char alice;   // Aliceの都合
 char bob;     // Bobの都合
 char carol;   // Carolの都合
 int ok;       // 参加可能な人数
 int unfixed;  // 参加未定（?）の人数
 int i;

 if ((fp = fopen (filename, "r")) == NULL){
   printf("ファイル %s のオープンに失敗しました", filename);
   exite(1);
 }
}

ATTEND sum(ATTEND d[MAX], int size)
{
  int i, ok, unfixed, totalok, totalunfixed;
  char date, alice, bob, carol;

  for(date = 0; i< size; i++){
    d[i].totalok = +d[i].ok;
    d[i].totalunfixed = +d[i].unfixed;
  }

void print(ATTEND d[MAX], int size)
{
  int i;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
         year, month, day,
         item.alice, item.bob, item.carol,
         item.ok, item.unfixed );
  printf("----------------------------------------------------\n");
  print()
}
