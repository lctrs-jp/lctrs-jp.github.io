#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[])
{
  struct todo item[100];
  int i=0, j, k, n, year, month, day, len;
  FILE *fp;
  char *out[100], buf[256];

  /*起動時引数の確認*/
  if(argc != 3){
    printf("使い方:<プログラム名><日にち><ファイル名>\n");
    exit(1);
  }

  /*ファイルを開く*/
  if((fp=fopen(argv[2],"r"))==NULL){
    printf("ファイルを開けませんでした\n");
    exit(1);
  }

  /*ファイルの内容を読み込む*/
  while(fgets(buf,256,fp)!=NULL){
    len=strlen(buf);
    if(len>0 && buf[len-1]=='\n'){
      len--;
      buf[len]='\0';
    }
    sscanf(buf,"%d/%d/%d %d:%d %c",&item[i].year, &item[i].month, &item[i].day, &item[i].hour, &item[i].minute, item[i].content);
    i++;
  }
  fclose(fp); //ファイルを閉じる

  /*指定された日にちを読み込む*/
  sscanf(argv[1],"%d/%d/%d",&year, &month, &day);


  printf("%d%d%d\n",year,month,date);
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year,item[i].month,item[i].day,item\
	 [i].hour,item[i].minute,item[i].content);

  /*結果を表示する*/
  for(i=0;i<k;i++)
    if(item[i].year > year && item[i].month > month && item[i].day > day) 
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year,item[i].month,item[i].day,item[i].hour,item[i].minute,item[i].content);
  
  return 0;
}
