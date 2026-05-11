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

   typedef struct attendance ATTENDANCE;
   void print(ATTENDANCE item[MAX], int size);
   int load(ATTENDANCE item[MAX], char *filename, int size);
};

int main(int argc, char *argv[]))
{
  ATTENDANCE person[MAX];
  int i, size;
  if (argc < 3){
    printf("Usage: %s filename1 filename2 filename3\n", argv[0]);
    exit(1);
  }

  for(i = 1; i < argc; i++) {//データの読み込み
    size = load(person, argv[i]);
  }
  print(person);
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

int load(ATTENDANCE item[MAX], char *filename, int size)
{
  FILE *fp;
  char buf[LEN], name[MAX];
  char date[9];
  int i, len, schedule, id ;
  if((fp = fopen(filename, "r") == NULL) {
      printf("ファイル %s  のオープンに失敗しました", filename);
      exit(1);
    }
    fgets(buf, LEN, fp);
    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0';
    strcpy(name, &buf[1]);

    while (fgets(buf, LEN, fp) != NULL){
      len = strlen(buf);
      if (len > 0 && buf[len - 1] == '\n')
	buf[len - 1] = '\0';
      sscanf(buf, "%s %d",  date, &schedule);
  for(i = 0; i < size; i++){
  if(strcmp(name, item[i].name) == 0){
  id = i;
  break;
    }
  }
  if(i == size){
  strcpy(d[i].name,name);
  id = size;
  size++;
} 
  if (strcmp(person, "Alice") == 0)
    item[id].alice = schedule;
  else if (strcmp(person, "Bob") == 0)
    item[id].bob = schedule;
  else if (strcmp(person, "Carol") == 0)
    item[id].carol = schedule;
  else
    printf("Wrong person error: %s\n", person);
    }
    return size;
   }
   
  void print(ATTENDANCE d[MAX],int size)
  { 
    int i;
    printf("-----------------------------------------\n");
    printf("date\t\tAlice\tBob\tCarol\n");
    for(i = 0; i < size; i++)
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	   year, month, day,
	   item.alice, item.bob, item.carol,
	   item.ok, item.unfixed );
    printf("-----------------------------------------\n");
  }
