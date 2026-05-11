#include <stdio.h>
#include<string.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
todo list[MAX];
int num = 0;

int main()
{
  FILE *fopen ("mytodo.txt","rb") = *fp;



  int len;
  char buf[MAX];
  while (fgets(buf, MAX, fp) > 0){
    if((len = strlen(buf)) > 0 && buf[len - 1] == '\n'){
      len --;
      buf[len] = '\0';
    }
    sscanf(buf, "%d/%d/%d",&year, &month, &day);

  int x,y,z;
  char str;

  fgets(str);
  printf("str=%s",str);
  sscanf(str, "%d/%d/%d",&x,&y,&z);
  printf("x=%d,y=%d,z=%d",x,y,z);

  if(x >=2015 && y >= 01 && z > 29)printf("no data\n");
  else
    for(

  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month, item.day, item.hour, item.minute, item.content );
  return 0;
}
