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

typedef struct attendance ATT;


int main(int argc, char *argv[])
{
  ATT students[MAX], avg;
  int n, year, month, day, j, size, len;
  char buf[LEN];
  FILE *fp;

  if (argc < 4){
    printf("Usage: %s <filename1> ... <filename2>\n", argv[0] );
    exit(1);
  }
  /* struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;
  
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );*/
  for (j= 1; j<4; j++){
  if ((fp = fopen (argv[j], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました\n", argv[j] );
    exit(1);
  }
  while( fgets(buf,LEN,fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0'; 
    sscanf(buf, "%4d/%2d/%2d ");
	   }

  struct attendance item = { "", 'o', '?', 'x', 1, 1 };

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
         year, month, day,
         item.alice, item.bob, item.carol,
         item.ok, item.unfixed );
  }  
  return 0;
}
