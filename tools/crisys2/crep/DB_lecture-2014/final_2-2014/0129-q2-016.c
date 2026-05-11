#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 200

int now;

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};
typedef struct attendance ATT;

void load(ATT item[MAX], char *fname); /*引数から読み込む*/

int main(int argc, char *argv[])
{
  ATT item[MAX];
  int i, n, year, month, day;

  if(argc < 2){
    printf("引数が正しくありません\n");
    exit (1);
  }

  /* itemの初期化*/
  for(i=0; i < MAX; i++){
    item[i].ok = 0;
    item[i].unfixed = 0;
  }
  /* ファイルから読み込む*/
  for(i = 1; i < argc; i++)
    load(item, argv[i]);

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-----------------------------------------\n");
  for(i=0; i<now; i++){

    sscanf( item[i].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
 
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   item[i].alice, item[i].bob, item[i].carol);
  }

  printf("-----------------------------------------\n");
  return 0;
}

void load(ATT item[MAX], char *fname)
{
  FILE *fp;
  char buf[LEN], name[50], date[10], ox;
  int i, len, frag=0;

  if((fp = fopen(fname, "r")) == NULL){
    printf("file open error[%s]\n", fname);
    exit (1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if(len > 0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);

  if(strcmp(name, "Alice")==0)
    frag = 1;
  else if(strcmp(name, "Bob")==0)
    frag = 2;
  else if(strcmp(name, "Carol")==0)
    frag = 3;
  else{
    printf("Alice, Bob, Carol以外の人は使用できません");
    exit (1);
  }
  while(fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len-1]=='\n')
      buf[len-1] = '\0';

    sscanf(buf, "%s %c", date, &ox );
    for(i=0; i < now; i++){
      if(strcmp(date, item[i].date) == 0){
	if (ox == 'o')
	  item[i].ok ++;
	else if(ox == '?')
	  item[i].unfixed++;

	switch (frag){
	case 1:
	  item[i].alice = ox;
	  break;
	case 2:
	  item[i].bob = ox;
	  break;
	case 3:
	  item[i].carol = ox;
	  break;
	}
	break;
      }
    }

    if(i == now){
      if(now >= MAX){
	printf("日数が多すぎます");
	exit (1);
      }
      strcpy(item[i].date, date);
      switch (frag){
    case 1:
      item[i].alice = ox;
      break;
    case 2:
      item[i].bob = ox;
      break;
    case 3:
      item[i].carol = ox;
      break;
      }
      now++;
    }
  }
}
