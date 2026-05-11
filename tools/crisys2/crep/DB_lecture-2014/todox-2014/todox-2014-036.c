#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 101


struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

typedef struct todo TOD;

int main(int argc, char *argv[])
{
  TOD cat[MAX];
  FILE *fp;
  char buf[256];
  int i = 1, top = 1, len;

  if((fp = fopen(argv[2], "r")) == NULL) {
    printf("Cannot open text file.\n");
    exit(1);
  }

  sscanf(argv[1], "%d/%d/%d", &cat[0].year, &cat[0].month, &cat[0].day);

  while(fgets(buf, 256, fp) != NULL) {

    len = strlen(buf);
      if(len > 0 && buf[len - 1] == '\n')
	buf[len - 1] = '\0';

      sscanf(buf, "%d/%d/%d %d:%d %s", &cat[i].year, &cat[i].month, &cat[i].day, &cat[i].hour, &cat[i].minute, cat[i].content);

      i++;
  }

  while(top < MAX){  

    if(cat[0].year - cat[top].year >= 0){
      if(cat[0].month - cat[top].month >= 0){
         if(cat[0].day - cat[top].day >= 0)
	   top++;
         else {
           top++;
           break;}
      }
      else{
	top++;
	break;}
    }
    else {
      top++;
      break;}
  }


while(top < i){
  printf("%d/%d/%d %d:%d %s\n", cat[top].year, cat[top].month, cat[top].day, cat[top].hour, cat[top].minute, cat[top].content);

  top++;
 }

return 0;
}
