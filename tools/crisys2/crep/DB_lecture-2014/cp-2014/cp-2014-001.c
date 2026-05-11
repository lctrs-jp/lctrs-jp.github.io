#include <stdio.h>

int copy(char* src, char* trg);
FILE* open_rw(char* file, char mode);

int main(int argc, char* argv[])
{
  if(argc == 3){
    if( copy(argv[1], argv[2]) ){
      printf("Error occurred in copy().\n");
      return 1;
    }
  }else{
    printf("Usage: ./copy [source] [target]\n");
  }

  return 0;
}

int copy(char* src, char* trg)
{
  FILE* sp;
  FILE* tp;
  int ch;

  // open
  sp = open_rw(src, 'r');
  tp = open_rw(trg, 'w');
  if(sp == NULL || tp == NULL){
    printf("Error occurred in open_rw().\n");
    return 1;
  }

  // copy
  printf("Copy %s to %s\n", src, trg);
  while( (ch = fgetc(sp)) != EOF ){
    fputc(ch, tp);
  }

  // close
  fclose(sp);
  fclose(tp);

  return 0;
}

FILE* open_rw(char* file, char mode)
{
  FILE* fp;

  // update fp
  fp == NULL;
  if(mode == 'r'){
    fp = fopen(file, "r");
    if(fp == NULL)
      printf("Failed to open \"%s\".\n", file);
  }else if(mode == 'w'){
    fp = fopen(file, "r");
    if(fp == NULL){
      fp = fopen(file, "w");
    }else{
      printf("\"%s\" already exist.\n", file);
      fclose(fp);
      fp = NULL;
    }
  }else{
    printf("Mode error.\n");
  }

  return fp;
}
