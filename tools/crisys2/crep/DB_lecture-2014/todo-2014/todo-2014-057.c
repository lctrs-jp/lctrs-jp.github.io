#include <stdio.h>
#include <stdlib.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[])
{
  FILE *fp[100];
  int i,j,x,y,z;
  char buf[100];
  for(i=1;i!='\0';i++){
    if((fp[i-1]=fopen(argv[i],"r"))==NULL)
      exit(1);
    else{
      while(fgets(buf,100,fp[i-1])!=NULL){
        sscanf(buf, "%d/%d/%d" , &x, &y, &z);
        struct todo item = {x, y, z,};
        printf("%4d/%.2d/%.2d %.2d:%.2d %s\n", item.year, item.month,
               item.day, item.hour, item.minute, item.content);
      }
    }
  }

  j=0;
  while(j<-i){
    fclose(fp[j]);
    j++;
  }

  return 0;
}
