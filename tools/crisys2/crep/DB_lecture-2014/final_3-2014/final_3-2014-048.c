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

typedef struct attendance ATT;

int main(int argc, char *argv[])
{
  ATT item[MAX];
  int n, year, month, day, size, id, i,len;
  FILE *fp;
  char buf[LEN], name[50], date2[9], moji;
  int a, b;

  if(argc < 2){
    printf("Usage: %s <filename1> …\n", argv[0]);
    exit(1);
  }

  for(i=1; i<4; i++){
    if((fp = fopen(argv[i], "r")) == NULL){
      printf("ファイルオープンに失敗\n");
      exit(1);
    }

    fgets(buf, LEN, fp);
    len = strlen(buf);

    if( len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0';
    strcpy(name, &buf[1]);

    size = 0;
    while(fgets(buf, LEN, fp) != NULL){
      len = strlen(buf);
      if( len > 0 && buf[len - 1] == '\n')
	buf[len - 1] = '\0';

      sscanf(buf, "%s %s",date2, moji);

      for(i = 0; i < size; i++){
	if(strcmp(date2, item[i].date) == 0){
	  id = i;
	  break;
	}
      }
      if(i == size){
	strcpy(item[i].date, date2);
	id = size;
	size++;
      }

      if(strcmp(name, "Alice") == 0)
	item[id].alice = moji;
      else if(strcmp(name, "Bob") == 0)
	item[id].bob = moji;
      else if(strcmp(name, "Carol") == 0)
	item[id].carol = moji;
      else
	printf("Wrong name error: %s\n", name);
    }
  }

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("------------------------------------------\n");

  for(i=0;i<size;i++){
    sprintf( item[i].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("date\t\tAlice\tBob\tCarol\n");
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	   year, month, day,
	   item[i].alice, item[i].bob, item[i].carol );
  }
  printf("------------------------------------------\n");

  a = 0;
  b = 0;
  for(i=0;i<size;i++){
    sscanf( item[i].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    if(item[i].alice == 'o')
      a += a;
    else if(item[i].alice == '?')
      b += b;

    if(item[i].bob == 'o')
      a += a;
    else if(item[i].bob == '?')
      b += b;

    if(item[i].carol == 'o')
      a += a;
    else if(item[i].carol == '?')
      b += b;

    printf("%4d/%2d/%2d [ok:%d, ?:%d]\n", year, month, day, a, b);
  }

  return 0;
}
