#include <stdio.h>
#include <stdlib.h>


  int main(int argc, char *argv[])
  {
    FILE *fs, *fd;   
    char str[256];

    if (argc!=3){
      printf("error\n");
      exit(1);
    }
    if ((fs=fopen(argv[1],"r"))==NULL){
      printf("can not open the file\n");
      exit(1);
    }
    if ((fd=fopen(argv[2],"w"))==NULL){
      printf("can not open the file\n");
      exit(1);
    }

    while (fgets(str,256,fs)!=NULL){
      fputs(str,fd);
    }

    fclose(fs);
    fclose(fd);

    return 0;
  }
