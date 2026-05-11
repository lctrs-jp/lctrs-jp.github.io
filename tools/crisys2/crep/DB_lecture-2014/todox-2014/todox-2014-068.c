#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content [256];
};
int main(int argc, char *argv[])
{
  FILE *fp;
  int choice;
  int i;
  if( argc == 2 ){
    if( (fp = fopen(argv[1],"r")) == NULL ){
      fprintf(stderr,"Error: can't open %s.\n", argv[1]);
      exit(1);
    }
    for (;;){
      i= fgetc(fp);
      if(i=EOF)
	break;
      putchar(fp)
	}
      printf("%s", fp)
  }else if( argc > 2 ){
    fprintf(stderr,"Usage: %s [filename]\n", argv[0] );
    exit(1);
  }

  return 0;
}

