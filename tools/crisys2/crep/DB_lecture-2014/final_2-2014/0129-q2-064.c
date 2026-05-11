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

int main(int argc, char *argv[])
{
  int len;
  char buf[LEN];
  FILE *fp;
  if (argc != 4){
    printf("Usage: %s <filename> <filename> <filename>\n", argv[0] );
    exit(1);
  }

  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day, num, i;

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );

    if ((fp = fopen (argv[1], "r")) == NULL) {
    printf("ファイル %s のオープンに失敗しました", argv[1]);
  }
  num = 0;
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0';
  }
  sscanf(buf,"%8d %s", &item[num].date,item[num].alice);
  
  if((fp = fopen (argv[2], "r")) == NULL){
    printf("ファイル %s のオープンに失敗しました", argv[2]);
  }
  
  if((fp = fopen (argv[3], "r")) == NULL){
    printf("ファイル %s のオープンに失敗しました", argv[3]);	   	   
  
  return 0;
}
