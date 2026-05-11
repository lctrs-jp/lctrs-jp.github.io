#include <stdio.h>
#include <math.h>

int excon(char *in);
int main(int argc,char *argv[])
{
  if(argc==1)
    return 0;
  printf("%d",excon(argv[1]));
  return 0;
}

  int excon(char *in)
{
  int i;
  char *p=in;
  if(*in==0)
    return 0;
  for(i=0;*p;p++)
    i++;
  return pow(26,i-1)*(*in-'A'+1)+excon(in+1);
}
