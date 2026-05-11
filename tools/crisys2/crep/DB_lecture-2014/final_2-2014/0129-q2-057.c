#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct attendance{
  int date;
  int date2;
  int year;
  int month;
  int day;
  char alice;
  char bob;
  char carol;
  };

int main(int argc, char *argv[])
{
  struct attendance item[100];
  FILE *fp;
  int len;
  int i = 0;
  int k = 0;
  int l;
  char buf[100];
  
  if(argc < 2){
    printf("Usage: %s filename1... filename2\n", argv[0]);
    exit(1);
  }

  if((fp = fopen(argv[1], "r")) == NULL){
    printf("ファイル%sのオープンに失敗しました", argv[1]);
    exit(1);
  }

  while(fgets(buf,273,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\n';
    sscanf(buf, "%d %s", &item[i].date, item[i].alice);
    i++;
  }
  fclose(fp); 

  if((fp = fopen(argv[2], "r")) == NULL){
      printf("ファイル%sのオープンに失敗しました", argv[2])
	exit(1);
    }
  while(fgets(buf,273,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\n';
    sscanf(buf "%d" &item[k].date2);
      
    for(l = 0; l < i; l++){
      if(item[l].date == item[k].date2)
        sscanf(buf, "%d %s", &item[l].date, item[l].bob);  
      }     
    if(l == i){
        i = i + 1;
        sscanf(buf, "%d %s", &item[i].date, item[i].carol);
    }
      k++;
    }    
  fclose(fp);
  k = 0; 

    while(fgets(buf,273,fp) != NULL){
      len = strlen(buf);
      if(len > 0 && buf[len - 1] == '\n')
        buf[len - 1] = '\n';
      sscanf(buf "%d" &item[k].date2);

      for(l = 0; l < i+1; l++){
        if(item[l].date == item[k].date2)
          sscanf(buf, "%d %s", &item[l].date, item[l].carol);
      }
      if(l == i){
        i = i + 1;
        sscanf(buf, "%d %s", &item[i].date, item[i]);
      }
      k++;
    }
    fclose(fp);
    for(k = 0; k<i; k++){
      item[k].day = item[k].date % 100;
      item[k].month = (item[k].date / 100) % 100;
	item[k].year = item[k].date / 10000; 
    }
    printf("date\t\tAlice\tbob\tcarol\n");
    for(k = 0; k < i; k++){
      printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	     item[k].year, item[k].month, item[k].day,
	     item[k].alice, item[k].bob, item[k].carol );
    }
    return 0;
}
  
