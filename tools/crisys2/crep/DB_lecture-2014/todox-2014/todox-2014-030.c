#include <stdio.h>

struct todo {
  int year[2];
  int month[12];
  int day[31];
  int hour[24];
  int minute[60];
  char content[256];
};

int main(int argc, char *argc[])
{
  FILE *fp;
  char ch;
  int a,i;

  item.year[0] = 2014;
  item.year[1] = 2015;

  item.day[a] = a;
  item.hour[a] = a;
  item.minute[a] = a;


  if( argc != 2 ){
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  if((fp = fopen(arg[1], "r")) == NULL ){
    fprintf(stderr, "Error: %s does not exist.\n", argv[1] );
    exit(1);
  }

  ch = fgets(fp)


    sscanf(ch, "%d/%d/%d", &x, &y, &z );

  if( x > item.year[0] ){
       printf("%4d/%2d/%2d %2d:%.2d %s\n",item.year[1], item.month,
              item.day, item.hour, item.minute, item.content );
  }
  else{
    if( y >= item.month[i])
      if( z >= item.day[j])
        for( k = j;k < 31;k++)
          printf("%4d/%2d/%2d %2d:%.2d %s\n",item.year[0], item.month,
                 item.day[k], item.content);


  return 0;
}
