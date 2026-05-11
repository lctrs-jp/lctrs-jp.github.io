#include <stdio.h>
#include <string.h>
#include <math.h>
void exc(char *apv);     

  int main(int argc, char *argv[]){
  printf("%s\n", argv[1]);
  exc(argv[1]);
  return 0;
}
void exc(char *apb){
  int i, j, p, len;
  len = strlen(apb);
  p = 0;
  for(i = len-1; i >= 0; i--){
    j = pow(26, len-1);
    p = j*(*(apb) - 'A'+1) + p;
  }
    printf("%d\n",p);
  }
