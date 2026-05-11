#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
  FILE *from,*to;
  char ch,watch;
  
  /*読み込みのためにfromを開く*/
  if ((from = fopen(argv[1],"r")) ==NULL){
    printf("can't open file\n");
    exit(1);
  }
  
    
  
  

  /*書き込みのためにtoを開く*/
  if ((to = fopen(argv[2],"w")) ==NULL){
    printf("Can't open file\n");
    exit(1);
  }

  if(argc == 4 && !strcmp(argv[3],"watch"))
    watch=1;
  else
    watch=0;

  /*コピーする*/
  
  while ((ch=fgetc(from)) != EOF){
    fputc(ch,to);
    if(watch)
      putchar(ch);
  }
  
  fclose(from);
  fclose(to);

  return 0;
}
