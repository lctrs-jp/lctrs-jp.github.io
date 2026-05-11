#include <stdio.h>
#include <stdlib.h>
#define MAX 256
int main(int argc, char*argv[])
{
  FILE *sour ;
  int year, month, day, year0, month0, day0;
  char s[MAX], buf[MAX] ;

  sour = fopen(argv[2],"r+");
  sscanf(argv[1],"%d/%d/%d",&year0,&month0,&day0 );
 
  while(fgets(s,MAX,sour) != NULL){
     sscanf(buf,"%d/%d/%d",&year,&month,&day );
     if(year > year0 && month > month0 && day > day0)
       printf("%s",s);
   }

 fclose(sour);

 return;
}
