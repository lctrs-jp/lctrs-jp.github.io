//期末試験問題４
//問題３に対してより都合のよい人数が多い順に表示するプログラム
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 273
#define MAX 30

struct attendance {
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

typedef struct attendance At;
int load(char *filename, At d[MAX], int size);
void print(At d[MAX], int size);
void sort(At d[MAX], int size);

int main(int argc, char *argv[]){
  At item[MAX];
  int i, size=0;

  //構造体の初期化
  for (i = 0; i < MAX; i++){
    strcpy(item[i].date, "");
    item[i].alice = '\0';
    item[i].bob = '\0';
    item[i].carol = '\0';
    item[i].ok = 0;
    item[i].unfixed = 0;
  }

  if (argc != 4){
    printf("Usage: %s filename1 filename2 filename3\n", argv[0]);
    exit(1);
  }

  for (i = 1; i < argc; i++){
    size = load(argv[i], item, size);
  }
  sort(item, size);
  print(item, size);

  return 0;
}

int load(char *filename, At d[MAX], int size){
  FILE *fp;
  char buf[LEN], name[20];
  int len;
  char date[LEN], ox;	//都合がいいかどうかを保持する変数
  int i, id;

  if ((fp = fopen(filename, "r")) == NULL){
    printf("Cannot open %s.\n", filename);
    exit(1);
  }
  //１行目を読み込んでnameに名前を入力
  fgets(buf, LEN, fp);
  len = strlen(buf);
  if (len > 0 && buf[len - 1] == '\n'){
    buf[len - 1] = '\0';
  }
  strcpy(name, &buf[1]);
  
  //２行目以降の都合をitemへ入力
  while (fgets(buf, LEN, fp) != NULL){
    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n'){
      buf[len - 1] = '\0';
    }
    sscanf(buf, "%s %c", date, &ox);
    for (i = 0; i < size; i++){
      if (strcmp(date, d[i].date) == 0){
	id = i;
	break;
      }
    }
    if (i == size){
      strcpy(d[i].date, date);
      id = size;
      size++;
    }
    if (strcmp(name, "Alice") == 0){
      d[id].alice = ox;
    }
    if (strcmp(name, "Bob") == 0){
      d[id].bob = ox;
    }
    if (strcmp(name, "Carol") == 0){
	d[id].carol = ox;
    }
    if (ox == 'o'){
      d[id].ok++;
    }else if (ox == '?'){
      d[id].unfixed++;
    }
  }

  return size;

}

void print(At d[MAX], int size){
  int i, n, year, month, day;
  int rank, j;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-----------------------------------------\n");

  for (i = 0; i < size; i++){
    sscanf(d[i].date, "%d", &n);
    day = n % 100; month = (n / 100) % 100; year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day, d[i].alice, d[i].bob, d[i].carol);
  }

  printf("-----------------------------------------\n");

  for (i = 0; i < size; i++){
    sscanf(d[i].date, "%d", &n);
    day = n % 100; month = (n / 100) % 100; year = n / 10000;

    rank = i + 1;
    for (j = 0; j < size; j++){
      if (d[i].ok == d[j].ok && d[i].unfixed == d[j].unfixed){
	rank = i + 1;
      }
    }

    printf("%2d: %4d/%2d/%2d [ok:%d, ?:%d]\n",
	   rank, year, month, day, d[i].ok, d[i].unfixed);
  }

}

void sort(At d[MAX], int count){
  int a, b;
  At t;

  for (a = 1; a < count; a++){
    for (b = count - 1; b >= a; b--){
      if (d[b - 1].ok < d[b].ok ||
	  ( d[b - 1].ok == d[b].ok && d[b - 1].unfixed < d[b].unfixed )){
	t = d[b - 1];
	d[b - 1] = d[b];
	d[b] = t;
      }
    }
  }
  
}
