#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int t;

  if (strlen(argv[1]) ==1)
    t = *argv[1] - 64;

  else if (strlen(argv[1]) ==2)
    t = 26*(*argv[1]-64) + (*(argv[1]+1) - 64);

  else if (strlen(argv[1]) ==3)
    t = 676*(*argv[1]-64) + 26*(*(argv[1]+1)-64) + *(argv[1]+2) -64;

  else if (strlen(argv[1]) ==4)
    t = 17576*(*argv[1]-64) + 676*(*(argv[1]+1)-64) + 26*(*(argv[1]+2)-64) + *(argv[1]+3) -64;

  else if (strlen(argv[1]) ==5)
    t = 456976*(*argv[1]-64) + 17576*(*(argv[1]+1)-64) + 676*(*(argv[1]+2)-64) +26*(*(argv[1]+3) -64) + *(argv[1]+4) -64;
  
  printf("%d\n", t);
  return 0;
}
