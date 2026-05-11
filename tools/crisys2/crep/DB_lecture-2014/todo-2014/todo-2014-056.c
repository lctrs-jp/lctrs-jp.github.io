#include <stdio.h>
#include <string.h>

#define STRING 256
#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

void printItem(struct todo item);
void printItems(struct todo* items, int size);
void test(void);
void getEval(char* arg, struct todo* eval);
FILE* myopen(char* file);
int read(char* file, struct todo* items);
void find(struct todo* items, int size, struct todo eval);

int main(int argc, char** argv)
{
  struct todo items[MAX];
  int size = 0;
  struct todo eval;	// for argv[1]

  getEval(argv[1], &eval);
  size = read(argv[2], items);
  find(items, size, eval);

  //printItems(items, size);	// for debug

  return 0;
}

void printItem(struct todo item)
{
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month, item.day, item.hour, item.minute, item.content );
         
  return;
}

void printItems(struct todo* items, int size)
{
  int i;

  for(i=0; i<size; i++)
    printf("%4d/%2d/%2d %2d:%.2d %s\n", items[i].year, items[i].month,
	   items[i].day, items[i].hour, items[i].minute, items[i].content );
}

void test(void)
{
  struct todo item = { 2014, 12, 10, 17, 0, "プログラミング課題提出" };
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
	 item.day, item.hour, item.minute, item.content );
  return;
}

void getEval(char* arg, struct todo* eval)
{
  int y,m,d;

  sscanf(arg, "%4d/%2d/%2d", &y, &m, &d);

  eval->year = y;
  eval->month = m;
  eval->day = d;

  return;
}

FILE* myopen(char* file)
{
  return fopen(file, "r");
}

int read(char* file, struct todo* items)
{
  FILE* fp = myopen(file);
  char buf[STRING];
  int i = 0;

  int y,mon,d,h,min;

  // read 1 line from a file
  for(i=0; i<MAX; i++){
    if( fgets(buf, STRING, fp) == NULL ) break;
    buf[strlen(buf)-1] = '\0';	// remove '\n'
    sscanf(buf, "%d/%d/%d %d:%d %s", &y, &mon, &d, &h, &min, items[i].content);
    items[i].year = y;
    items[i].month = mon;
    items[i].day = d;
    items[i].hour = h;
    items[i].minute = min;
	 
    //printf("%s\n", buf);	// for debug
    //printf("%4d/%2d/%2d %2d:%.2d %s\n", items[i].year, mon, d, h, min, items[i].content);
  }

  // file close
  fclose(fp);

  return i;
}

void find(struct todo* items, int size, struct todo eval)
{
  int i;

  for(i=0; i<size; i++)
    if(items[i].year > eval.year)
      printItem(items[i]);
    else if(items[i].year == eval.year)
      if(items[i].month > eval.month)
        printItem(items[i]);
    else if(items[i].year == eval.year
            && items[i].month == eval.month)
      if(items[i].day >= eval.day)
        printItem(items[i]);

  return;
}
