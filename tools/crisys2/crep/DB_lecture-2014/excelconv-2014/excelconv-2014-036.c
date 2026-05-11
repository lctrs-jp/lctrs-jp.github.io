#include <stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  int i,k=0;
    for(i=0;argv[1][i]!='\0';i++){
    k= k*26+(argv[1][i]-64);
    }
    printf("%d\n",k);
  return 0;
}
