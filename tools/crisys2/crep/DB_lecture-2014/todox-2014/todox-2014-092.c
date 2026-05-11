#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct todo {
   int year;
int month;
int day;
int hour;
int minute;
char content  [MAX];
};
typedef struct todo;

int main(int argc , char *argv[])
{
  





  FILE *fp;
  int i, j, len,size=0;
  char buf[MAX];
 
  if(argc != 3){
    printf("ファイルの指定がありません\n");
    exit(1);
  }

 if((fp =fopen(argv[2] , "r")) == NULL){
   printf("ファイルが開けません\n");
   exit(1);
 }

 while(fgets(item.content,MAX,fp) != NULL){
   sscanf(buf,"%.2d/%.2d/%.2d/%.2d/%.2d" , &item.year, &item.month, &item.day, &item.hour, &item.minute);

   len = strlen(item.content);
   if(len > 0 && item.content[len-1] == '\n')
    item. content[len-1] = '\0';

   for (i = 1; i < size; i++)
            if(strncmp(argv[1], buf) >0 ){
	 printf("%s %s \n", buf , item.content);
            }
 }
   fclose(fp);
   return size;
}





