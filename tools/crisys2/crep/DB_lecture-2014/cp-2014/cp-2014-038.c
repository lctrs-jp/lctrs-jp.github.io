#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  FILE *fp2;
  char ch;
  

  if((fp = fopen(argv[1],"r")) == NULL){
    printf("読み込むファイルが存在しません。\n");
    exit(1);
  }
  if((fp2 = fopen(argv[2],"r")) == NULL){
    fp2 = fopen(argv[2],"w");
  }else{
    printf("書き込むためのファイルが既に存在しています\n");
    exit(1);
  }
  
  while(ch = fgetc(fp)){
    if(ch == EOF){
      break;
    }
    if(fputc(ch,fp2) == EOF){
      break;
    }
  }
  
  fclose(fp); 
  fclose(fp2);
  
  return 0;
}

