//第二回中間テスト 12/17                                                              
//問題2                                                               
//

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

int main(int argc,char *argv[])
{
  int y,m,d;
  int yy,mm,dd,hh,min;
  int ch;
  char filename[256];
  char cont[256];
  char s1[16],s2[16],s3[256];
  FILE *fp;
 int *p;
 int count;
 struct todo list[20];
 
 
  if(argc == 3){
  
    sscanf(argv[1],"%d/%d/%d",&y,&m,&d);
	//printf("%d %d %d \n",y,m,d);
  	
    if((fp = fopen(argv[2],"r")) == NULL){   //fileopen
      printf("cannot found file.\n");
      return 0;
    }
/*	
	while( ( ret = fscanf( fp, "%s %s %s", s1, s2, s3 ) ) != EOF ){
	 	sscanf(s1,"%d/%d/%d",yy,mm,dd);			
  }
	*/
	while (( ch = fgetc(fp)) != EOF ) {
  	//	sscanf(ch,"%d/%d/%d %s %s",yy,mm,dd,tt,cc);
   		p = &ch;
   		/*
   		list[count].year = yy;
   		list[count].month = mm;
   		list[count].day = dd;
   		list[count].hour = hh;
   		list[count].minute = min;
   		list[count].content = cont;
   		*/
   		count++;
   		p++;
   		putchar(ch);	
   	}
  	
   int i;
//   for(i=0;i<count;i++){	   }
   
   }
   

  fclose(fp);
  return 0;
}
