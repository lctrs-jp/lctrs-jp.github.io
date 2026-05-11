#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 273
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
} item[MAX];

int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[LEN], name[LEN], mark[LEN], date[LEN];
  int n, year, month, day, len, i, size, k;

  if (argc != 4){
    printf("usage: %s <filename> <filename> <filename>\n", argv[0]);
    exit(1);
  }

  for (i=1; i<4; i++){
    if ((fp = fopen(argv[i], "r")) == NULL){
      printf("ファイル %s がオープンできません\n", argv[i]);
      exit(1);
    }
  }
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("---------------------------------------\n");

  fp = fopen(argv[1], "r");
  fgets(buf, LEN, fp);
  len = strlen(buf);
  if (len > 0 && buf[len-1] == '\n'){
    buf[len-1] = '\0';
  }
  strcpy(name, &buf[1]);

  k=1;
  size=0;
  while (fgets(buf, LEN, fp) != NULL){
    len = strlen(buf);
    if (len > 0; buf[len-1] == '\n'){
      buf[len-1] = '\0';
    }
    sscanf(buf, "%s %s", date, mark);

    item[k].date = date;
    k++;
    size++;
  }


  for (i=1; i<4; i++){
    fp = fopen(argv[i], "r");
    fgets(buf, LEN, fp);
    len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n'){
      buf[len-1] = '\0';
    }
    strcpy(name, &buf[1]);    

    while (fgets(buf, LEN, fp) != NULL){
      len = strlen(buf);
      if (len > 0; buf[len-1] == '\n'){
	buf[len-1] = '\0';
      }
      sscanf(buf, "%s %s", date, mark);

      if (strcmp(name, "Alice") == 0){
	for (k=1; k<size+1 ; k++) {
	  if (item[k].date == date)
	    item[k].alice = mark;
	}
      }
      if (strcmp(name, "Bob") == 0){
        for (k=1; k<size+1 ; k++) {
          if (item[k].date == date)
            item[k].bob = mark;
        }
      }
	if (strcmp(name, "Carol") == 0){
	  for (k=1; k<size+1 ; k++) {
	    if (item[k].date == date)
	      item[k].carol = mark;
	  }
	} 
    }
  }

  for (k=1; k<size+1; k++){
    item[k].date = n;
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\t\n",
	   year, month, day,
	   item[k].alice, item[k].bob, item[k].carol);
  }
  printf("------------------------------------\n");

  return 0;
}
