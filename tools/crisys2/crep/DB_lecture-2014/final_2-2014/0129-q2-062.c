#include <stdio.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};det[10], *p;

void main (int argc, char *argv[])
{
  FILE *fp;
  char str[100], *member[3], *poss[3];
  int i, t, n, year, month, day, date, count=0;
       
    if (argc != 4){
      printf("3つのファイル名を指定して実行してください");
      exit(1);
    }
  for (i = 1; i < 4; i++){
    if (strcmp(argv[i], "alice.txt") == 0){
      member[i-1] = "Alice";
    }else if (strcmp(argv[i], "bob.txt") == 0){
      member[i-1] = "Bob";
    }else if (strcmp(argv[i], "carol.txt") == 0){
      member[i-1] = "Carol";
    }else if (i == 3){
      printf("3つのファイル名を指定して実行してください");
      exit(1);
    }
  }
  for (i = 0;i < argc-1; i++){

    p = det;

    if ((fp = fopen(argv[i+1], "rb")) == NULL){
      printf("ファイル(%s)がディスク上に存在しません。\n",argv[i+1]);
      exit(1);
    }

    while (fgets(str,100,fp) != NULL){
      sscanf ( date, "%d %s", &n, &poss );
      day = n % 100  ; month = (n / 100) % 100; year = n / 10000;
      }

      p++; 
    }
    printf("date\t%s\t%s\t%s\n",member[0],member[1],member[2]);
    printf("---------------------------------------------\n");
    p = det;

    for(i = 0;i < count; i++,p++)
      printf("%d/%d/%d\t%3d\t%3d\t%3d\t%3d\n",year, month, day, /**/poss[0],/**/poss[1],/**/poss[2]);

    printf("---------------------------------------------\n");
    return;
  }
