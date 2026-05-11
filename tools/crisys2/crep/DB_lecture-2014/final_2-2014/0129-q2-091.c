#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define NUM 3
#define STRING 256
#define TRUE 1
#define FALSE 0
#define ALICE "Alice"
#define BOB "Bob"
#define CAROL "Carol"

typedef struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int size = 0;	// items array size

void initItems(struct attendance* items);
void printItems(struct attendance* items);
void read(FILE** people, struct attendance* items);
void myopen(FILE** people, char** argv);
void test(void);

int main(int argc, char** argv)
{
  struct attendance items[MAX];
  FILE* people[NUM];

  if(argc != 4){
    puts("argument error");
    exit(1);
  }else{
    initItems(items);
    myopen(people, argv);
    read(people, items);
  }

  printItems(items);

  //test();

  return 0;
}

void initItems(struct attendance* items)
{
  int i;

  for(i=0; i<MAX; i++){
    items[i].alice = '\0';
    items[i].bob = '\0';
    items[i].carol = '\0';
  }

  return;
}

void printItems(struct attendance* items)
{
  int i;
  int n, year, month, day;
  char border[STRING] = "-------------------------------------";

  printf("date\t\tAlice\tBob\tCarol\n");
  puts(border);
  for(i=0; i<size; i++){
    sscanf( items[i].date, "%d", &n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;
  
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
  	 year, month, day,
  	 items[i].alice, items[i].bob, items[i].carol);
  }
  puts(border);

  return;
}

void read(FILE** people, struct attendance* items)
{
  int i,j;
  int new;
  FILE* person;
  char me[STRING];
  char buf[STRING];

  char date[STRING];
  char schedule;

  for(i=0; i<NUM; i++){
    person = people[i];
    fgets(buf, STRING, person);
    buf[strlen(buf)-1] = '\0';
    strcpy(me, buf+1);
    while( fgets(buf, STRING, person) != NULL ){
      new = TRUE;
      buf[strlen(buf)-1] = '\0';
      sscanf(buf, "%s %c", date, &schedule);
      if( !strcmp(me, ALICE) ){
        for(j=0; j<size; j++){
          if( !strcmp(items[j].date, date) ){
            items[j].alice = schedule;
            new = FALSE;
          }
        }
        if(new == TRUE){
          strcpy(items[size].date, date);
          items[size].alice = schedule;
          size++;
        }
      }else if( !strcmp(me, BOB) ){
        for(j=0; j<size; j++){
          if( !strcmp(items[j].date, date) ){
            items[j].bob = schedule;
            new = FALSE;
          }
        }
        if(new == TRUE){
          strcpy(items[size].date, date);
          items[size].bob = schedule;
          size++;
        }
      }else if( !strcmp(me, CAROL) ){
        for(j=0; j<size; j++){
          if( !strcmp(items[j].date, date) ){
            items[j].carol = schedule;
            new = FALSE;
          }
        }
        if(new == TRUE){
          strcpy(items[size].date, date);
          items[size].carol = schedule;
          size++;
        }
      }else{
        puts("error");
        exit(1);
      }
    }
  }

  return;
}

void myopen(FILE** people, char** argv)
{
  int i;

  for(i=0; i<NUM; i++)
    people[i] = fopen(argv[i+1], "r");

  return;
}

void test(void)
{
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

  return;
}
