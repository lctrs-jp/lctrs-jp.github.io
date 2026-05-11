#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 30

struct attendance {
  int date; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTEND;

int load(ATTEND d[MAX], char *filename);
int main(int argc, char *argv[])
{
  int i, size, year[MAX], month[MAX], day[MAX];
  ATTEND item[MAX];

  //入力ミスのチェック
  if(argc < 2){
    printf("Usage: %s filename1 ... filename3\n", argv[0]);
    exit(1);
  }

  for(i = 1; i< argc; i++){
    size = load(item, argv[i]);
  }

  for(i = 0; i < MAX; i++){
    day[i] = item[i].date % 100;
    month[i] = (item[i].date / 100) % 100;
    year[i] = item[i].date / 10000;
  }

  

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");
  for(i = 0; i < size; i++){
  printf("%4d/%2d/%2d\t%c\t%c\t%c\t\n", year[i],month[i],day[i],item[i].alice,item[i].bob,item[i].carol/*item.ok,item.unfixed*/ );
  }
  printf("-------------------------------------\n");
  return 0;

}

int load(ATTEND d[MAX], char *filename)
{
  FILE *fp;
  char buf[MAX], name[MAX], ox;
  int len, i, date, id, size;


  //各テキストファイルを開く
  if((fp = fopen(filename, "r")) == NULL){
    printf("ファイル%sの読み込みに失敗しました。", d[i]);
    exit(1);

  }

  fgets(buf,MAX,fp);
  len = strlen(buf);
  if(len > 0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);

  size = 0;

  while(fgets(buf, MAX, fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d %c", &date, &ox);
    id = id - 1;
    size++;
    d[id].date = date;

  if(strcmp(name,"Alice")==0)
    d[id].alice = ox;
  else if(strcmp(name, "Bob")==0)
    d[id].bob = ox;
  else if(strcmp(name, "Carol")==0)
    d[id].carol = ox;
  }
  return size;
}
