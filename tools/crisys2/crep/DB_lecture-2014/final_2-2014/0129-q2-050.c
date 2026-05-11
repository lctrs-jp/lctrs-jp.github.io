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
  // int ok;       // 参加可能な人数
  // int unfixed;  // 参加未定（?）の人数
};

int main(int argc, char *argv[])
{
  char buf[LEN];
  FILE *fp;

  if (argc != 4){ //引数の数を確認
    printf("Usage: %s <filename> <filename> <filename>\n", argv[0] );
    exit(1);
  }

  if ((fp = fopen (argv[1], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました",argv[1]);
    exit (1);
  }

  struct attendance item[12]; //item2[31];
  int len, num;
  int n, year, month, day;
  num = 0;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");

  while (fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    //printf("buf = %s\n", buf);

    sscanf ( buf, "%d %s", &n, &item[num].alice );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
    //item2[day] = item[num];

    printf("%4d/%2d/%2d\t%c\n",
	   year, month, day,
	   item[num].alice);//, item.bob, item.carol );//,
    //item.ok, item.unfixed );
    num++;

  }
  fclose(fp);


  // if ((fp = fopen (argv[2], "r")) == NULL) {
  //  printf ("ファイル %s のオープンに失敗しました",argv[2]);
  // exit (1);
  // }

  // while (fgets(buf,LEN,fp) != NULL){
  //  len = strlen(buf);
  //  if( len >0 && buf[len-1]=='\n')
  //   buf[len-1] = '\0';
  //  printf("buf = %s\n",buf);
  // }



  //  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
  //	 year, month, day,
  //	 item2[day].alice, item2[day].bob, item2[day].carol );//,
	 // item.ok, item.unfixed );
  printf("-------------------------------------\n");
  return 0;
}
