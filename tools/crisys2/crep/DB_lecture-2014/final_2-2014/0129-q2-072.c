#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct attendance{
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int year;
  int month;
  int day;
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};
typedef struct attendance ATTE;

int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[MAX], name[MAX];
  int k, l, m, n, o, len, size;
  ATTE d[MAX];
  if(argc != 4){
    printf("ファイルの数が正しくありません");
    exit(1);
  }
  for(k = 1; k < argc; k++){
  if((fp = fopen(argv[k],"r")) == NULL) {
    printf("ファイルが開けません");
    exit(1);
  }
  fgets(buf,MAX,fp);
  len = strlen(buf);

  size = 0;
  for(o = 0; o < MAX; o++){
  if(len > 0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(name, &buf[1]); 
  for(l = 1; l < MAX; l++){
    if(strcmp(name, "Alice") == 0) 
  sscanf( &buf[l], "%d %s", &n, &d[o].alice);
    else if(strcmp(name, "Bob") == 0)
  sscanf( &buf[l], "%d %s", &n, &d[o].bob);
    else if(strcmp(name, "Carol") == 0) 
  sscanf( &buf[l], "%d %s", &n, &d[o].carol);
    else{
      printf("一致する名前が見つかりません");
    exit(1);
  }
  d[o].day = n % 100;
  d[o].month = (n / 100) % 100;
  d[o].year = n / 10000;
  }
  }
  }

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");
  for(m = 0;m < MAX ;m++){
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t\n",
	 d[m].year, d[m].month, d[m].day,
	 d[m].alice, d[m].bob, d[m].carol
	 );
  }
  printf("-------------------------------------\n");

  return 0;
}
