#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int split(char buf[], char *out[]);

int main(int argc, char *argv[])
{
  int x,y,z,l,m,n,o;
  char *out[80], ch, *p;
  FILE *fp;



  split (argv[0],out);

  sscanf(argv[1],"%d/%d/%d", &x, &y,&z);
  printf("%d%d%d", x,y,z);

  /* 読み込みのためにmyfile を開く*/
  if((fp = fopen("mytodo.txt", "r"))
     == NULL){
    printf("Can't open file\n");
    exit(1);
  }
  /* ファイルを読み込み直す*/
  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
      putchar(ch);
  }
  fclose(fp);
  return 0;
}







  return 0;
}



int split(char buf[], char *out[]){
  int l, m, n;
  l=0;
  m=0;

 again:
  while(buf[l]==' ')
    l++;

  if(buf[l]=='\0')
    if(m==0)
      return 0;
    else
      return m;

  if(buf[l]!=' '&&buf[l]!='\0'){
    *(out+m)=&buf[l];
    m++;
    while(buf[l]!=' '&&buf[l]!='\0')
      l++;
    buf[l]='\0';
    l++;
    goto again;}


  return 0;
}





