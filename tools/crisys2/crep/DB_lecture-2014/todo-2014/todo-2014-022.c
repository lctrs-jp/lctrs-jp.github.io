#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item;

int main(int argc, char *argv[])
{
  FILE *fp;
  int x, y, z;
  int i;
  int a, b, c; 
  char str[MAX]; 

  if((fp = fopen(argv[2],"r")) == NULL){
    printf("読み込むファイルが存在しません。\n");
    exit(1);
  }
  
  sscanf(argv[1],"%d/%d/%d", &x, &y, &z);
  
  
  while(fgets(str, MAX, fp) != NULL){
    sscanf(str,"%d/%d/%d",&a, &b, &c);
    if(x < a ){
      printf(str);
    }else{
      if(x == a){
	if(y< b){
	  printf(str);
	}else{
	  if(z == c){
	    printf(str);
	  }
	}
      }
    }
  }
  
      fclose(fp);
    return 0;

  }    

  

  
		      
		      
		      
		      
		      
		      
		      
		      
		      
