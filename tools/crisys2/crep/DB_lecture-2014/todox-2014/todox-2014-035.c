#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct  todo {
int year;
int month;
int day;
int time;
char content  [256];
}list[100];

void split (char buf[], char *out[]);
int main(int argc, char *argv[] )
{
  FILE *fp;
  int a, b, c, x, y, z;
  char buf[100],*out[100] ;
  int len, num=0;
  sscanf(argv[1],"%d/%d/%d", &a,&b,&c);
  
  if((fp = fopen(argv[2],"r"))==NULL){
    printf("ファイルを開けません\n");
    exit(1);
  }
  while(fgets(buf,100,fp)!=NULL){
    len = strlen(buf);
    if(len>0 && buf[len-1]=='\n'){
      buf[len-1]='\0';
      split(buf[len], out[2]);
      sscanf(out[0],"%d,%d,%d",&x,&y,&z);
      if(x>a){
      list[num].year=x;
      list[num].month=y;
      list[num].day=z;
      	}         
      strcpy(list[num].content,&out[2]);
      strcpy(list[num].time,&out[1]); 
      }
    num++;
  }
    fclose(fp);
  
    for(num=0; num<100 ;num++)  	    
  printf("%4d/%2d/%2d %2d:%.2d %s\n", list[num].year, list[num].month,
       list[num].day, list[num].time, list[num].content );
return 0;
}

  void split(char buf[], char *out[]){
    int i, cnt = 0;
    for( i = 0 ; buf[i] != '\0' ; i++ ){
      if( buf[i] == ' ' ) {
	buf[i] = '\0';
	continue;
      }else{
	if( i <= 0 || buf[i-1] == '\0' ){
	  out[cnt] = buf + i;
	  cnt ++;
	}
      }
    }
    return ;
  }   
