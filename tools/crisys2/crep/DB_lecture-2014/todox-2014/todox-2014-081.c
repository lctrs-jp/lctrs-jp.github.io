#include <stdio.h>

struct todo {
  int year;
  int month;
  int ay;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo EVENT;

int main(int argc, char *argv[])
{
  struct todo item = { 2014,12,10,17,0,"プログラミング課題提出"};
  EVENT list[MAX];
  int i,op,size;
  char temp[LEN], *filename;
  filename = argv[1];

  size = load(filename,list);
  sort(filename,list);

  for(i=0;i<size;i++){
  printf("%4d/%2d/%2d %2d:%.2d %s\n",item.year,item.month,item.day,item.hour,item.minute,item.content);
  }

  return 0;
}



int load(char *filename, EVENT list[]){
  FILE *fp;
  char buf[LEN];
  int len,size = 0;
  if ((fp = fopen (filename, "r")) == NULL) {
    printf ("can not open the file");
    exit (1);
  }

  while( fgets(buf,MAX,fp) != NULL ){
    sscanf(buf,"%d/%d/%d/%d:%.d %s",&year,&month,&day,&hour, &minute,&content);
    printf("%d/%d/%d/%d:%.d %s",year,month,day,hour, minute,content);
 }
  fclose(fp);
  return size;
}
