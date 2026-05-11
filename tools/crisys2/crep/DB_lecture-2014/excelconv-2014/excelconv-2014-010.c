#include <stdio.h>
#include <string.h>

int excelconv(char *trg,char *p);


int main()
{
  char trg[5],*p;

  fgets (trg, 5, stdin);
  p=trg;  
  printf("%s >%d\n", trg , excelconv(&trg[strlen(trg)-1],p) );

  return 0;
}


int excelconv(char *trg,char *p)
{  
  if (trg==p)    
    return (*trg) - 64;
  else
    return (*trg) - 64 + (excelconv(trg - 1,p))*26;
}
      
