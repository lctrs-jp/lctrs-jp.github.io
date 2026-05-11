#include <stdio.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo TODO;

int main(int argc, char *argv[])
{
  TODO list[MAX];
  int op, size;
  char *filename;
  FILE *fp;
  filename = argv[2];
  int x, y, z,; char buf[] = argv[1];

  sscanf(buf, "%d/%d/%d", &x, &y, &z);
}
int load(char *filename, TODO list[]){
  FILE *fp;
  char buf[256];
  int len,size = 0;
  if ((fp = fopen (filename, "r")) == NULL) {
    printf ("can't open file",filename);
    exit (1);
  }
  while (fgets(buf,256,fp) != NULL){
}


void output(FILE *fp, TODO list[], int size)
{
  int i;
  for (i = 0;i < size;i++){
    fprintf(fp,"%d/%d/%d %d:%d %s\n",list[i].year, list[i].month, list[i].day, list[i].hour, list[i].minute, list[i].content);
  }
}
