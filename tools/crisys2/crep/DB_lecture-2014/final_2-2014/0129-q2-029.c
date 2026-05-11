#include<stdio.h>
#define MAX 30
struct attendance {
  char date[9]; //日にち
  char alice; //Aliceの都合
  char bob; //Bobの都合
  char carol; //Carolの都合
  int ok; //参加可能な人数
  int unfixed; //参加未定（？）の人数
} ;

int main(){
  struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  int n, year, month, day;

  sscanf( item.date, "%d", &n );
  day = n % 100 ; month = ( n / 100 ) % 100; year = n / 10000;

  void main ( int argc, char *argv[])
  {
    FILE *fp;
    char str[100], *sub[3], name[10];
    int i, t ;


  if (arg != 4){
    printf("３つのファイル名を指定して実行してください（例）./ex2-081430563 alice.txt bob.txt carol.txt\n\n");
    exit(1);
      }

  for ( i = 1; i < argc; i++ ){
    if (strcmp(argv[i], "alice.c\txt") == 0){
      sub[i-1] = "Alice";
    }else if (strcmp(argv[i], "bob.txt") == 0){
      sub[i-1] = "Bob";
    }else if (strcmp(argv[i],"carol.txt") == 0){
      sub[i-1] = "Carol";
    }else if (i == 3){
      printf("３つのファイル名を指定して実行してください（例）./ex2-081430563 alice.txt bob.txt　carol.txt\n\n");
      exit(1);
    }
  }

  for (i = 0;i < argc - 1; i++){

    if ((fp = fopen(argv[i+1], "rb")) == NULL){
      printf("ファイル(%s)がディスク上の存在しません。\n",argv[i+1]);
  exit(1);
}

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");

  printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?;%d]\n",
	 year, month, day,
	 item.alice, item.bob, item.carol, item.ok, item.unfixed );
  printf("-------------------------------------\n");
  return 0;
}
