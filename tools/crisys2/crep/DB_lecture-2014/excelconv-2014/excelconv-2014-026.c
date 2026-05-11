#include<stdio.h>
#include<string.h>
int conv(char *x);

int main(int argc,char *argv[])
{
  int a;
 a= conv(argv[1]);
 printf("%d",a);
  return 0;
}
int conv(char *x)
{
  int i,cnt,j,a,tol;
  for(i=0;i<strlen(x);i++)
    {
  cnt=*(x+i)-64;
      a=1;
      for(j=strlen(x)-i;j>1;j--)
          a=a*26;
          tol=tol+a*cnt;
	  
    }	
	  return tol;
}
