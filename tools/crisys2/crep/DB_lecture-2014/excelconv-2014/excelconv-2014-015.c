#include <stdio.h>
#include <string.h>
#include <math.h>

void execlconv(char *l);


int main(void)
{

  execlconv("A");

  return 0;
}


void execlconv(char l[]){
  int m, n, j, k;
  m=0; k=0; n=0; j=0;

  if (l[j]=='\0')
    printf("%d\n",k);

  else{
    m=l[j]-64;
    n=strlen(l);
    j++;
    k=k+m*26^(n-j);
    execlconv(l++);}}

