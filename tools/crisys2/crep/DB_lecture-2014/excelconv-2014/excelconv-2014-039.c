#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
  char*st=argv[1];
  int a,b,c=0,d,t=0;

  for(a=0;a<strlen(st);a++){
    b=st[a]-'A'+1;
    d=1;
    for(c=strlen(st)-a;c>1;c--)
      d=d*26;
    t=t+d*b;
  }
  printf("%d\n",t);
  return 0;
}
