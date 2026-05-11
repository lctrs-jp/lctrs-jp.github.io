#include <stdio.h>

   todo ｛
   int year;
int month;
int day;
int hour;
int minute;
char content[256];
｝;
｝


int main(int argc, char *argv[])
{
  FILE *fp;
  int i;

  if((fp=fopen(argv[1],"w"))==NULL) {
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }

  fprintf(fp, "%d/%d %d:%d %s", item.mouth,item.day,item.hour,item.minute,item.content; 

   fclose(fp);

	  if((fp=fopen(argv[1],"r"))==NULL){
	    printf("ファイルを開くことができません\n");
	    exit(1);
	  }
	  
	  fscanf(fp, "%d/%d %d:%d %s", item.mouth,item.day,item.hour,item.minute,item.content;
		 fclose(fp);

		 return 0;
}
