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
  //  int ok;       // 参加可能な人数
  //  int unfixed;  // 参加未定（?）の人数
} item[MAX];

int main(int argc, char *argv[])
{

  FILE *fp;
  char buf[LEN],name[LEN],rw[MAX];
  int i,j,n, year, month, day, size=0,date,len;

  // 入力方法のエラー表示
  if( argc < 2 ){
    printf("入力が正しくありません。");
    exit(1);
  }

  // ファイルを順番に処理
  for ( j = 1; j < argc; j++) {
    // ファイルオープンのエラー
    if ( (fp = fopen (argv[j], "r") ) == NULL ) {
      printf("Can't open file.");
      exit(1);
    }

    // 1行目の名前の部分を，1文字目を除いてコピー
    fgets(buf,LEN,fp);
    len = strlen(buf);
    if ( len > 0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    strcpy(name,&buf[1]);

    // ファイルから日付と参加可否を取り込む
    while ( fgets(buf,LEN,fp) != NULL ) {
      len = strlen(buf);
      if ( len > 0 && buf[len-1] == '\n' )
	buf[len-1] = '\0';
      sscanf(buf,"%d %s", &date, rw);
      size++; // 項目数
      printf("%d\n",date);

      // 人に応じてそれを振り分ける
      if (strcmp(name,"Alice") == 0) {
      	item[date].alice = rw; // ここが何かおかしい
      }
      else if (strcmp(name,"Bob") == 0) {
      	item[date].bob = rw;
      }
      else if (strcmp(name,"Carol") == 0) {
 	item[date].carol = rw; 
      } 
      else
 	printf("Error.");
    }
  }
  
  // 結果の出力
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------");
  for ( i = 0; i < size; i++ ) {
    sscanf( item.date[9], "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   item[date].alice, item[date].bob, item[date].carol);
  }
  printf("-------------------------------------"); 
  return 0;
} 
