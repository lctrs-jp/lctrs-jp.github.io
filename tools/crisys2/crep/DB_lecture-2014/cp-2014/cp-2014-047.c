#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
  int i;
  char in[100],*p;
  FILE *fp,*fg;

  if((fp = fopen(argv[1],"r")) == NULL){
    printf("コピー元ファイルのオープンに失敗しました\n");
    exit(1);
  }
  for(i=0;;i++){
    if((in[i] = fgetc(fp)) == EOF)
    break;
  }
  fclose(fp);


  if((fg = fopen(argv[2],"r")) == NULL){
    fp = fopen(argv[2],"w");
    p = in;
  for(;*p;p++){
    fputc(*p,fp);
    }    
    exit(1);
  }
  else{
    printf("同名ファイルが既に存在します\n");
  }
  fclose(fg);
  fclose(fp);
  
  return 0;
}

  
  
