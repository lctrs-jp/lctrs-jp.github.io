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
}item[MAX];

void readfile(char *file, struct attendance item[]);

int main(int argc, char *argv[])
{
  struct attendance item[MAX];
  int n, year[MAX], month[MAX], day[MAX];
  int i;

  //引数のチェック
  if(argc < 2) {
    fprintf(stderr, "ファイルを指定してください\n");
    exit(1);
  }

  //変数の初期化
  for(i = 0; i < MAX; i++) {
    item[i].date[0] = '\0';
    item[i].alice = '\0';
    item[i].bob = '\0';
    item[i].carol = '\0';
    item[i].ok = 0;
    item[i].unfixed = 0;
  }
  
  //ファイルのオープン・読み込み・クローズ
  for(i = 1; i < argc; i++) {
    readfile(argv[i], item);
  }

  //結果表示
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");
  for(i = 0; i < item[i].date[0] != '\0'; i++) {
    sscanf(item[i].date, "%d", &n);
    day[i] = n % 100;
    month[i] = (n / 100) % 100;
    year[i] = n / 10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 year[i], month[i], day[i],
	 item[i].alice, item[i].bob, item[i].carol);
  }
  printf("-------------------------------------\n");

  return 0;
}

void readfile(char *file, struct attendance item[])
{
  FILE *fp;
  char buf[256];
  char name[256];
  char date[256];
  char ox;
  int i;

  //ファイルのオープン
  if((fp = fopen(file, "r")) == NULL) {
    fprintf(stderr, "ファイルを開くことができません\n");
    exit(1);
  }

  //ファイルの読み込み
  while(fgets(buf, sizeof(buf), fp) != NULL) {
    if(buf[0] =='#') {
      sscanf(buf, "#%s", name);
      continue;
    }
    sscanf(buf, "%s %c", date, &ox);
    for(i = 0; i < MAX; i++) {
      if(item[i].date[0] == '\0' || !strcmp(item[i].date, date)) {
	strcpy(item[i].date, date);
        if(!strcmp(name, "Alice")) item[i].alice = ox;
	else if(!strcmp(name, "Bob")) item[i].bob = ox;
	else item[i].carol = ox;
	break;
      }
    }
  }

  return;
}
