#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i,j,k,l=0;
  char mozi[5];

  i = strlen(argv[1]);
  strcpy(mozi, argv[1]);
  
  l = mozi[0]-64;
    if(i>=2){
      for(j=1;j < i;j++){
	k = mozi[j]-64;
	l = l*26 +  k;
      }
    }

  printf("%d\n",l);

    return 0;
}
      

  
