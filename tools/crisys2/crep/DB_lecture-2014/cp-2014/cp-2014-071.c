#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  FILE *souce, *dest;
  int a;
  if((souce = fopen("souce.txt", "r")) == NULL)
    {
      printf("It can't open sfile\n");
      exit(1);
    }
  if((dest = fopen("dest.txt", "w")) == NULL)
    {
      printf("It can't open dfile\n");
      exit(1);
    }
  while( (a = fgetc(souce)) != EOF)
	 fputc(a, dest);
 


  fclose(souce);
  fclose(dest);

 return 0;
}
