#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define LEN 256

struct attendance{
  char year; // 日にち
  char month;
  char day;
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
};

typedef struct attendance at;

void print(at d[MAX], int num);
int load(at d[MAX], char *file);

int main(int argc, char *argv[]){
  int i, num;
  at date[MAX];

  if(argc<2){
    printf("Usage: %s filename1 . . . filename2\n", argv[0]);
    exit(1);
  }

  for(i = 1; i < argc; i++){
    num = load(date, argv[i]);
  }
  print(date, num);

  return 0;
}

int load(at d[MAX], char *file)
{
  FILE *fp;
  char buf[LEN], name[LEN], ok;
  int len, num, n;

  if((fp = fopen (file, "r")) == NULL){
    printf("can't open %s", file);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);

  if(len > 0 && buf[len - 1] == '\n')
    buf[len - 1] = '\0';
  strcpy(name, &buf[1]);

  num = 0;
  while(fgets(buf, LEN, fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0';
    sscanf(buf, "%d %s", &n, &ok);
    d[num].day = n % 100;
    d[num].month = (n / 100) % 100;
    d[num].year = n / 10000;

    if (strcmp(name, "Alice") == 0)
      d[num].alice = ok;
    else if(strcmp(name, "Bob") == 0)
      d[num].bob = ok;
    else if(strcmp(name, "carol") == 0)
      d[num].alice = ok;
    else 
      printf("wrong name\n");
    num++;
  }

  return num;
}

void print(at d[MAX], int num)
{
  int i;

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("----------------------------------------\n");
  for(i = 0; i < num; i++){
    printf("%4d/%2d/%2d\t%d\t%d\t%d\n",
	   d[i].year, d[i].month, d[i].day,
	   d[i].alice, d[i].bob, d[i].carol);
  }
  printf("----------------------------------------\n");
}
