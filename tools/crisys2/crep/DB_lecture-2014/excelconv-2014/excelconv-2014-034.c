#include <stdio.h>
#include <string.h>

int hk(char *c);
int main(int argc, char *argv[100])
{
  int l,d;
  char str[6];

  l=strlen(argv[1]);
  d=l;

  for(l=strlen(argv[1]);*argv[1]!='\0';){
    if(l>0){
      str[l-1]=*argv[1]++;
      l--;
    }
  }
  str[d]='\0';

  printf("%d\n",hk(str));
  return 0;
}

int hk(char *c){
  int a='A'-1;
  int m,n;

  if(*(c+1)=='\0'){
    m=(*c-a);
    return m;
  }
  else if(*(c+1)!='\0'){
     n=(*c-a)+26*(hk(c+1));
    return n;
  }
}