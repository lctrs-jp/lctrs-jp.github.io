#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  int i, j;

  for(i = 0; i < strlen(argv[1]); i++){
    j = argv[1][i] + ( j * 26 ) - 64;
  }

  printf("%d\n",j);

  return 0;
}
