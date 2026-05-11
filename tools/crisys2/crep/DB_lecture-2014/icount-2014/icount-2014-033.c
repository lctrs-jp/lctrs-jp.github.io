#include <stdio.h>
#include <string.h>

int main(void)
{
  char i[100], c[10];
  int j, k;

  for (k = 0; k < 10; k++){
    c[k] = 0;
  }

  gets(i);

  for (j = 0; j < strlen(i); j++){
    for (k = 0; k < 10; k++){
      if (i[j] - 48 == k){
	c[k]++;
      }
    }
  }

  for (k = 0; k < 10; k++){
    printf("%dが%d個\n", k, c[k]);
  }

  return 0;
}
