#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{

  FILE *fp1, *fp2, *temp;
  char ch, *p;
  
  if((fp1 = fopen( argv[1], "r")) == NULL){
    printf("Can't open file1\n");
    exit(1);
  }
 
  if((fp2 = fopen( argv[2], "w")) == NULL){     
    printf("Can't open file2\n");
    exit(1);
  }
  
  while(!feof(fp1)){
    ch=fgetc(fp1);
    if (!feof(fp1))
      fputc(ch, fp2);

  }
  fclose(fp1);
  fclose(fp2);


  return 0;
} 
  
     
     
  

 
