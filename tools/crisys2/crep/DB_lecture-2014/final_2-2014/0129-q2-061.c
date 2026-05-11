#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define LEN 256

struct   attendance {
  int year;
  int month;
  int day;
  char no[5];
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};
char name[5][30];
typedef struct attendance ATT;
void print(ATT item[MAX],int size); 
int load(ATT item[MAX],char *filename,int size,int k);

int main(int argc,char *argv[]){
  
  if(argc < 4){
    printf("引数が足りません\n");
    exit(1);
  }
  ATT item[MAX];
  int i,size = 0,j;
    for(i = 1;i < argc;i++){ 
    size = load(item,argv[i],size,i-1); 
  }
    printf("date");
    
    printf("----------------------------------------------------------\n");
    for(i = 0;i < size;i++){
      printf("%4d/%2d/%2d\t",item[i].year,item[i].month,item[i].day);
      for(j=0;j < 3;j++){
	printf("%c\t",item[i].no[j]);
      }
      printf("\n");
    }
    
   
 return 0;
}
void print(ATT item[MAX],int size){
    
  return;
}
int load(ATT item[MAX],char *filename,int size,int k){
  FILE *fp;
  int i,len,year2,month2,day2,id;
  char buf[LEN],ok;
  if((fp = fopen(filename,"r")) ==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  fgets(buf,LEN,fp);
  len = strlen(buf);
  if(len >0 && buf[len - 1]=='\n')
    buf[len -1] = '\0';
  strcpy(name[k],&buf[1]); 
  while(fgets(buf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len >0&&buf[len-1] =='\n')
      buf[len-1] ='\0';
    sscanf(buf,"%4d%2d%2d %c",&year2,&month2,&day2,&ok);
    
    for(i = 0;i < size;i++){
      if(year2 == item[i].year && month2 == item[i].month && day2 == item[i].day){
	item[i].no[k] = ok;
  } 
    }
      if(i == size){
	item[i].year = year2;
	item[i].month = month2;
	item[i].day = day2;
	item[i].no[k] = ok;
	size++;
      
    }
  }
  
  return size;
}
  
