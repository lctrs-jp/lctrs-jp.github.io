#include <stdio.h>
#include <math.h>
#include <string.h>

int mypow(char a[])
{
  static t=0;
  if(a[0]!='\0'){
  t=t+pow(26,strlen(a)-1)*(a[0]-64);
  a++;
  mypow(a);
  }
  return t;
}

int main(void)
{
  char a[7];
  int i;

 for(i=0;i<=7;i++){
   a[i]=0;
 }

 scanf("%s",a);

 printf("%d\n",mypow(a));
  return 0;
}