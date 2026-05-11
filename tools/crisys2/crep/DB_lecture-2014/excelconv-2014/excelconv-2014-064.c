#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
  int i, j, k;
  j = 0;
  k = 1;
  int len = strlen(argv[1]);

  for(i = 0; i < len; i++){
    j = j + (argv[1][len - i - 1] - 64) * k;
    k = k * 26;
  }
  printf("%d\n",j);
  return 0;
}
