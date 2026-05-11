#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to, *too;/*教科書p,257-258を参考にしています。*/
  char ch;

  if(argc != 3){
    exit(1);
    printf("ERROR\n");
  }

  if((too = fopen(argv[2],"rb"))!=NULL){
    printf("ERROR\n");
    exit(1);
  }

  if((from = fopen(argv[1],"rb"))==NULL){
    printf("ERROR\n");
    exit(1);
  }

  if((to=fopen(argv[2],"wb"))==NULL){
    printf("ERROR\n");
    exit(1);
  }

  while(!feof(from)){
    ch=fgetc(from);
    if(ferror(from)){
      printf("ERROR\n");
      exit(1);
    }
    if(!feof(from))
      fputc(ch,to);
    if(ferror(to)){
      printf("ERROR\n");
      exit(1);
    }
  }

  if(fclose(from)==EOF){
    printf("ERROR\n");
    exit(1);
  }

  if(fclose(to)==EOF){
    printf("ERROR\n");
    exit(1);
  }

  return 0;
}
