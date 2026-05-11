#include <stdio.h>
#include <string.h>

int recurse(char *s, int n);
int main(int argc, char *argv[])
{
  printf("%d", recurse(argv[1],strlen(argv[1])));

  return 0;
}

int recurse(char *s, int n)
{
  if(!n)
    return n;
  return (*(s + n -1) -64) + 26 * recurse(s, n - 1);
}
