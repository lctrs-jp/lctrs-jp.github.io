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

int load(struct attendance memb[MAX], char *file, int size);
/*ファイルを読み込む関数*/
void printlist(struct attendance member[MAX], int size);
/*内容をリストにして表示する関数*/

int main(int argc, char *argv[])
{
  struct attendance member[MAX];
  int i, n, year, month, day, size = 0;

  if (argc < 2){
    printf("command <filename> <filename> <filename>\n");
    exit(1);
  }

  for (i = 1; i < 4; i++) {
    size = load(member, argv[i], size);
  }

  printlist(member, size);
  //sscanf( item.date, "%d", &n );

  /*

  */
  return 0;
}

int load(struct attendance member[MAX], char *file, int size)
{
  FILE *fp;
  char buf[LEN], name[LEN], date[9];
  char rep;
  int len, n, i;
  
  if ((fp = fopen(file, "r")) == NULL) {
    printf("file \"%s\" cannot open\n", file);
    exit(1);
  }
  
  fgets(buf, LEN, fp);
  len = strlen(buf);
  
  if (len > 0 && buf[len - 1] == '\n'){/*改行文字をヌル文字と置き換える*/
    buf[len-1] = '\0';
  }
  
  strcpy(name, &buf[1]);/*誰の日程なのか読み込む*/

  while (fgets(buf, LEN, fp) != NULL) {
    len = strlen(buf);
    
    if (len > 0 && buf[len-1]=='\n') {/*改行文字を取り除く*/
      buf[len-1] = '\0';
    }

    sscanf(buf, "%s %c", date, &rep);
    //    printf("%s %c\n", date, rep);

    for (i = 0; i < size; i++) { /*すでに日付があればそこに追加*/
                                 /*なければ配列を拡張し追加*/
      if (strcmp(member[i].date, date)){
	if (strcmp(name, "Alice") == 0){
	  member[i].alice = rep;
	  i = 0;
	  break;
	} else if (strcmp(name, "Bob") == 0){
	  member[i].bob = rep;
	  i = 0;
	  break;
	} else if (strcmp(name, "Carol") == 0){
	  member[i].carol = rep;
	  i = 0;
	  break;
	}
      }
    }
    
    if (i == size){
      strcpy(member[size].date, date);
      if (strcmp(name, "Alice") == 0){
	member[size].alice = rep;
      } else if (strcmp(name, "Bob") == 0){
	member[size].bob = rep;
      } else if (strcmp(name, "Carol") == 0){
	member[size].carol = rep;
      } else {
	printf("There is not such person\n");
      }
      size++;
    }
  }
  
  return size;
}

void printlist(struct attendance member[MAX], int size){
  int n, day, month, year, i;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("---------------------------------------\n");
  for (i = 0; i < size; i++) {
    sscanf(member[i].date, "%d", &n);/*年月日に変換*/
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   member[i].alice, member[i].bob, member[i].carol);
  }
  printf("---------------------------------------\n");

  return ;
}
