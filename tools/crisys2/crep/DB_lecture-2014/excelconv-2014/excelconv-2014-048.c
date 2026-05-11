#include <stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
  int i,j[10],k=0,n=0;
  for(i=0;argv[1][i]!='\0';i++)
    n=n++;
  for(i=0;argv[1][i]!='\0';i++)
    { j[i]=(int)pow(26,n-i-1)*(argv[1][i]-64);
	k=k+j[i];
	}
    printf("%d\n ",k );
  return 0;}
