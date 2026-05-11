#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
}item;

typedef struct attendance ab;
int main(int argc, char *argv[])
{
  int i, size =0, a, len, n =0, day, month,year;
  FILE *fp;
  char buf[MAX],subject[MAX] ,aa;

  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2...filename3\n", argv[0] );
    exit(1);
  }
  

  for (i = 1 ; i < argc ; i++ ){
  if( (fp = fopen (argv[i], "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", argv[i]);
    exit(1);
  }
  }
  
  fgets(buf, MAX, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(subject, &buf[1]);
  printf("date\t%s\n",subject);

  while( fgets(buf, MAX, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    sscanf(buf,"%d %s",&a, aa );
      }




  printf("--------------------------------------\n");
  
  day = a % 100;
  month = (a / 100) % 100;
  year = a / 10000;

  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 day,month,year,item.alice, item.bob, item.carol,item.ok, item.unfixed );

  return 0;
}


