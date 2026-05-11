#include <stdio.h>
#include <string.h>

int main()
{
  char inp[100];
  int n[10], i, j, l;

  printf("Input a string.");
  fgets(inp, 100, stdin);

  l = strlen(inp);

  for(j = 0; j < 10; j++)
    n[j] = 0;
  for(i = 0; i < l; i++)
    for(j = 0; j < 10; j++)
      if((47 < inp[i]) && (inp[i] < 58))
        if(inp[i] == j + 48)
          n[j]++;
  for(j = 0; j < 10; j++)
    printf("The number of %d is : %d\n", j, n[j]);

  return 0;
}
