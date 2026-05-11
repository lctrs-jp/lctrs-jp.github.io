#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, t;
  char c[6];

  for(i = 0; argv[1][i] != '\0'; i++)
    c[i] = argv[1][i];

  t = 0;
  for(i = 0; i < strlen(c); i++)
    t = t + (int)(c[i] + 1 - 'A')*(int)pow(26, strlen(c)-1-i);

  printf("%d\n",t);
 
  return 0;
}
