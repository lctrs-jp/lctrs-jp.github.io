#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp;
  int i, j;
  char *buf[100], *str[100];

  struct todo {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    char contain[256];
  }item[100];

  sscanf(argv[1],"%d/%d/%d",&item[0].year,&item[0].month,&item[0].day);

  if((fp = fopen(argv[2],"r")) == NULL){
    printf("ファイルを開くことに失敗しました。\n");
    exit(1);
  }

  do{
    fgets(str[i], 256, fp);
    i++;
  }while(!feof(fp));
  fclose(fp);

  for(i = 1;item[i] == '\0';i++)
    sscanf(buf,"%d/%d/%d",&item[i].year,&item[i].month,&item[i].day);



  for(j = 0;item[j] == '\0';j++)
    printf("%4d/%2d/%2d %2d:%.2d %s\n",item[j].year,item[j].month,item[j].day,item[j].hour,item[j].minute,item[j].content);

 return 0;
}
