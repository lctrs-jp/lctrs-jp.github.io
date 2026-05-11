#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
  char str[7];
  int num[7], i, ans=0;
  
  for(i=0; i<strlen(argv[1]); i++)
    str[i] = *(argv[1]+i);
  
  for(i=0; i<strlen(argv[1]); i++){
    num[i] = (int)str[strlen(argv[1])-1-i] - 64;
    ans = ans + pow(26,i) * num[i];
  }
  printf("%d\n",ans);

  return 0;
}
