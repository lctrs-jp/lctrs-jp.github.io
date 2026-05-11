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


typedef struct attendance OR;

void print(OR d[MAX], int size);
int load(OR d[MAX], char *filename);


int main(int argc, char *argv[])
{
  OR date[MAX];
  int i, size;

  if (argc < 2){
    printf("%s <ファイルの名前> <ファイルの名前> … というように入力してください", argv[0] );
    exit(1);
  }

  for ( i = 1 ; i < argc ; i++ ){
    size = load(date, argv[i]);
  }
  print(date, size);
  return 0;
}


int load(OR d[MAX], char *filename)
{

  FILE *fp;
  char buf[LEN], name[LEN];
  int len, date, or, size;

if ((fp = fopen (filename, "r")) == NULL) {
  printf ("ファイル %s のオープンに失敗しました", filename);
  exit(1);
 }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if( len > 0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);

  size = 0;
  date = 0;
  or = 0;
  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf, "%d %d", &date, &or);
    printf("%d %d", date, or);
    size++;
    if (strcmp(name, "alice") == 0)
      d[date].alice = or;
    else if (strcmp(name,"bob") == 0)
      d[date].bob = or;
    else if (strcmp(name,"carol") == 0)
      d[date].carol = or;
    else
      printf("Wrong name error: %s\n", name);
  }
  return size;
}








/*

  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day;

  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol,
	 item.ok, item.unfixed );

  return 0;
}

*/
