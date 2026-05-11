#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp1, *fp2;
  char ch; 
  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("Can't open source file\n");
    exit(1);
  }
  if((fp2 = fopen(argv[2], "r")) != NULL){
    printf("There is already dest file\n");
    exit(1);
    fclose(fp2);
  }
  if((fp2 = fopen(argv[2], "w")) == NULL){
    printf("Can't open dest file\n");
    exit(1);
  }
  while(feof(fp1) == 0){
    ch = fgetc(fp1);
    if(ferror(fp1))
      {
	printf("Error: Can't open file\n");
	exit(1);
      }
    if(feof(fp1) == 0)
      fputc(ch, fp2);
    if(ferror(fp2) != 0)
      {
	printf("Error: Can't write file\n");
	exit(1);
      }
  }
  
  fclose(fp1);
  fclose(fp2);
  return 0;
}
  
