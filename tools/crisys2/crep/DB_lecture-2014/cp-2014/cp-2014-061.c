#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
  char *error = "エラーが発生しました\n";
  char str;
  FILE *fpr,*fpw;
  
  if((fpr = fopen(argv[1],"r")) == NULL){
    printf(error);
    exit(1);
  }
  if(fpw = fopen(argv[2],"r")){
    printf(error);
    exit(1);
  }
  
  if((fpw = fopen(argv[2], "w")) ==NULL){
    printf(error);
    exit(1);
  }
  while(1){
    
    if((str = fgetc(fpr)) == EOF)    
      break;
    else{
      fputc(str,fpw);
      printf("%c",str);
      }
  }
   
  fclose(fpr);
  fclose(fpw);
  
  return 0;
}
